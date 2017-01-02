/**
 *  Copyright 2014-2016 CyberVision, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


#include <memory>
#include <string>
#include <cstdint>
#include <iostream>
#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <kaa/Kaa.hpp>
#include <kaa/event/registration/IUserAttachCallback.hpp>
#include <kaa/event/IFetchEventListeners.hpp>
#include <kaa/event/gen/EventFamilyFactory.hpp>
#include <kaa/event/gen/RFIDEventCF.hpp>
#include <kaa/event/gen/LedEventCF.hpp>
#include <kaa/event/gen/MotionEventCF.hpp>
#include <kaa/event/IFetchEventListeners.hpp>
#include <string.h>
#include <syslog.h>
#include <sys/wait.h>
#include <signal.h>

#include "bcm2835.h"
#include "config.c"
#include "rc522.c"
#include "rfid.c"

using namespace kaa;
#define SENSOR RPI_GPIO_P1_07
#define LED RPI_GPIO_P1_11
#define ACTIVE_VALUE 1
static const char * const RFID_EVENT_FQN = "com.roomie.rfid.RFIDEvent";
static const char * const MOTION_EVENT_FQN = "com.roomie.motion.MotionEvent";
static const char * const LED_EVENT_FQN = "com.roomie.led.LedEvent";
uint8_t HW_init(uint32_t spi_speed, uint8_t gpio);
void usage(char *);


uint8_t HW_init(uint32_t spi_speed, uint8_t gpio) {
	uint16_t sp;

	sp=(uint16_t)(250000L/spi_speed);
	if (!bcm2835_init()) {
		syslog(LOG_DAEMON|LOG_ERR,"Can't init bcm2835!\n");
		return 1;
	}
	if (gpio<28) {
		bcm2835_gpio_fsel(gpio, BCM2835_GPIO_FSEL_OUTP);
		bcm2835_gpio_write(gpio, LOW);
	}

	bcm2835_spi_begin();
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
	bcm2835_spi_setClockDivider(sp); // The default
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
	return 0;
}

void usage(char * str) {
	printf("Usage:\n%s [options]\n\nOptions:\n -d\t Debug mode\n\n",str);
}
/*
class LedEventCFListener: public LedEventCF::LedEventCFListener {
public:

    LedEventCFListener(EventFamilyFactory& factory) : eventFactory_(factory) { }

    virtual void onEvent(const nsLedEventCFListenerCF::LedEventCF& event, const std::string& source)
    {
        std::cout << "Kaa Demo ThermostatInfoRequest event received!" << std::endl;

        /*nsLEDEventCFListenerCF::ThermostatInfo info;
        info.degree.set_int(-5);
        info.targetDegree.set_int(10);
        info.isSetManually.set_null();

        nsThermostatEventClassFamily::ThermostatInfoResponse infoResponse;
        infoResponse.thermostatInfo.set_ThermostatInfo(info);
	
	
        eventFactory_.getThermostatEventClassFamily().sendEventToAll(infoResponse);
    }


private:
    EventFamilyFactory& eventFactory_;

};


class RFIDEventListenersCallback: public IFetchEventListeners {
public:

    RFIDEventListenersCallback(EventFamilyFactory& factory) : eventFactory_(factory) { }

   
    virtual void onEventListenersReceived(const std::vector<std::string>& eventListeners)
    {
	std::cout<<"Called Event Listeners";
       
	
	RFIDEventCF& rfidCF =eventFactory_.getRFIDEventCF();
	nsRFIDEventCF::RFIDEvent rfid;
	rfid.rfidId= "X";
	rfid.timeTag="Z";
	std::cout<<"Prepared to sent message";
        rfidCF.sendEventToAll(rfid);
	rfidCF.sendEvent(rfid, eventListeners[0]);
	std::cout<<"MessageSent";
      	
        std::cout << "Kaa Demo found " << eventListeners.size() << " event listeners" << std::endl;
	//EventFamilyFactory& eventFamilyFactory = kaaClient_.getEventFamilyFactory();
      	
	

    }

    virtual void onRequestFailed()
    {
        std::cout << "Kaa Demo event listeners not found" << std::endl;
    }

private:
    EventFamilyFactory& eventFactory_;

};
*/

class MotionEventListenersCallback: public IFetchEventListeners {
public:

    MotionEventListenersCallback(EventFamilyFactory& factory) : eventFactory_(factory) { }

   
    virtual void onEventListenersReceived(const std::vector<std::string>& eventListeners)
    {
	std::cout<<"Called Event Listeners";
	std::cout << "Kaa Demo found " << eventListeners.size() << " event listeners" << std::endl;
	
	MotionEventCF& motionCF =eventFactory_.getMotionEventCF();
	RFIDEventCF& rfidCF =eventFactory_.getRFIDEventCF();
	nsMotionEventCF::MotionEvent motion;
	nsRFIDEventCF::RFIDEvent rfid;

	uid_t uid;
	uint8_t SN[10];
	uint8_t SN_len=0;
	int tmp,i;
	char str[255];
	char *p;
	char sn_str[23];
	uint8_t use_gpio=0;
	uint8_t gpio=255;
	uint32_t spi_speed=10000000L;
	uint16_t CType=0;
	char status;

	uint8_t state = ACTIVE_VALUE; //Init state to HIGH	
	bcm2835_gpio_fsel(SENSOR, BCM2835_GPIO_FSEL_INPT);//SENSOR as input
         //bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);	   //LED as output
         bcm2835_gpio_set_pud(SENSOR, BCM2835_GPIO_PUD_UP);

       
	
	/*HW_init(spi_speed,gpio); 
	read_conf_uid(&uid);
	setuid(uid);
	InitRc522();
  	*/
	while(true) {
	/*
		status= find_tag(&CType);
		if (status==TAG_NOTAG) {
			//usleep(200000);
			continue;
		}else if ((status!=TAG_OK)&&(status!=TAG_COLLISION)) {continue;}

		if (select_tag_sn(SN,&SN_len)!=TAG_OK) {continue;}
		
		p=sn_str;
		*(p++)='[';
		for (tmp=0;tmp<SN_len;tmp++) {
			sprintf(p,"%02x",SN[tmp]);
			p+=2;
		}
		//for debugging
		*p=0;
		fprintf(stderr,"Type: %04x, Serial: %s\n",CType,&sn_str[1]);
		rfid.rfidId =&sn_str[1];
		rfidCF.sendEvent(rfid, eventListeners[0]);
	*/
        std::cout<<"MessageSent";
	bool presence;
		state = bcm2835_gpio_lev(SENSOR); //HIGH or LOW?
        	if(state != ACTIVE_VALUE)
		{
			printf("Movement at %d\n",(int)time(NULL));
			motion.isPresent=true;
			//motion.timeTag((int)time(NULL));
		}
		else
		{
			printf("Presence not detected %d\n",(int)time(NULL));
			//usleep(2);
			//Another extra overhead!
			motion.isPresent=false;
			//motion.timeTag((int)time(NULL));
			
		}
	motionCF.sendEvent(motion, eventListeners[0]);
	std::cout << "Kaa Demo found " << eventListeners.size() << " event listeners" << std::endl;
	
}
	
	/*PcdHalt();
	if (use_gpio) bcm2835_gpio_write(gpio, LOW);
	
	
	
	
	
	//usleep(5*1000000);
	
        //EventFamilyFactory& eventFamilyFactory = kaaClient_.getEventFamilyFactory();
	

	bcm2835_spi_end();
	bcm2835_close();
	close_config_file();
      	
	*/

    }
   virtual void onRequestFailed()
    {
        std::cout << "Kaa Demo event listeners not found" << std::endl;
    }

private:
    EventFamilyFactory& eventFactory_;

};

 
class UserAttachCallback: public IUserAttachCallback {
public:

    UserAttachCallback(IKaaClient& client) : kaaClient_(client) { }

    virtual void onAttachSuccess()
    {
	std::cout << "starting User attached" << std::endl;
	        //kaaClient_.findEventListeners(std::list<std::string>( {  RFID_EVENT_FQN}),
          //                       std::make_shared<RFIDEventListenersCallback>(kaaClient_.getEventFamilyFactory()));
	
	std::list<std::string> FQNs = {MOTION_EVENT_FQN};
	
 	//kaaClient_.findEventListeners(FQNs, std::make_shared< MotionEventListenersCallback>(kaaClient_.getEventFamilyFactory()));
kaaClient_.findEventListeners(FQNs, std::make_shared< MotionEventListenersCallback>(kaaClient_.getEventFamilyFactory()));
	std::cout << "User attached" << std::endl;
	
    }

    virtual void onAttachFailed(UserAttachErrorCode errorCode, const std::string& reason)
    {
        std::cout << "Kaa Demo attach failed (" << (int) errorCode << "): " << reason << std::endl;
    }

private:
    IKaaClient& kaaClient_;
};


int main()
{
   

    const std::string KAA_USER_ID("devuser@demoproject.org");
    const std::string  KAA_USER_ACCESS_TOKEN("83124659377411458680");
    
    
    /*
     * Initialize the Kaa endpoint.
     */
    auto kaaClient = Kaa::newClient();

    /*
     * Run the Kaa endpoint.
     */
    kaaClient->start();
  std::cout << "Event demo started" << std::endl;
    std::cout << "--= Press Enter to exit =--" << std::endl;

   // RFIDEventCFListener thermoListener(kaaClient->getEventFamilyFactory());  

   // kaaClient->getEventFamilyFactory().getRFIDEventCF().addEventFamilyListener(thermoListener);
	std::cout << "--= Press Enter to exit =--" << std::endl;    
	kaaClient->attachUser(KAA_USER_ID, KAA_USER_ACCESS_TOKEN, std::make_shared<UserAttachCallback>(*kaaClient));
    /*
     * Wait for the Enter key before exiting.
     */
    std::cin.get();

    /*
     * Stop the Kaa endpoint.
     */
    kaaClient->stop();

    std::cout << "Event demo stopped" << std::endl;

    return 0;
}
