/*
 * Copyright 2014-2016 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef RFIDEventCF_HPP_
#define RFIDEventCF_HPP_


#include <list>
#include <string>
#include <vector>
#include <sstream>

#include <cstdint>
#include <boost/any.hpp>

#include "kaa/logging/Log.hpp"
#include "kaa/gen/EndpointGen.hpp"
#include "kaa/event/IEventFamily.hpp"
#include "kaa/event/IEventManager.hpp"
#include "kaa/common/AvroByteArrayConverter.hpp"
#include "kaa/transact/TransactionId.hpp"
#include "kaa/observer/KaaObservable.hpp"
#include "kaa/context/IExecutorContext.hpp"
#include "kaa/utils/IThreadPool.hpp"

#include "kaa/event/gen/RFIDEventCFGen.hpp"

namespace kaa {

class RFIDEventCF : public IEventFamily
{
public:
    class RFIDEventCFListener
    {
    public:

        

        virtual ~RFIDEventCFListener() {}
    };

public:
    RFIDEventCF(IEventManager& manager, IKaaClientContext &context)
        : eventManager_(manager), executorContext_(context.getExecutorContext()), context_(context)
    {
        eventFQNs_ =         {} /* {"fqn1","fqn2","fqn3"} */;
    }

    virtual void onGenericEvent(const std::string& fqn
                              , const std::vector<std::uint8_t>& data
                              , const std::string& source)
    {
        if (fqn.empty()) {
            KAA_LOG_WARN("Failed to process incoming event: bad data");
            return;
        }

        if (listeners_.isEmpty()) {
            KAA_LOG_WARN(boost::format("Ignoring '%s' event: listener is not set") % fqn);
            return;
        }

        

    }

        void sendEventToAll(const nsRFIDEventCF :: RFIDEvent& event) {
        sendEvent(event);
    }

    void sendEvent(const nsRFIDEventCF :: RFIDEvent& event, const std::string& target = "")
    {
        executorContext_.getApiExecutor().add([=]
               {
                    std::vector<std::uint8_t> buffer;
                    AvroByteArrayConverter< nsRFIDEventCF :: RFIDEvent > converter;
                    converter.toByteArray(event, buffer);
                    eventManager_.produceEvent("com.roomie.rfid.RFIDEvent", buffer, target, TransactionIdPtr());
               });
    }

    void addEventToBlock(TransactionIdPtr trxId, const nsRFIDEventCF :: RFIDEvent& e, const std::string& target = "")
    {
        std::vector<std::uint8_t> buffer;
        AvroByteArrayConverter< nsRFIDEventCF :: RFIDEvent > converter;
        converter.toByteArray(e, buffer);
        eventManager_.produceEvent("com.roomie.rfid.RFIDEvent", buffer, target, trxId);
    }



    virtual const FQNList& getSupportedEventClassFQNs()
    {
        return eventFQNs_;
    }

    void addEventFamilyListener(RFIDEventCFListener& listener)
    {
        RFIDEventCFListener *listenerPtr = &listener;
        listeners_.addCallback(listenerPtr, [listenerPtr](const boost::any& value, const std::string& source, const std::string& fqn) {
            
        });
    }

    void removeEventFamilyListener(RFIDEventCFListener& listener)
    {
        listeners_.removeCallback(&listener);
    }

private:
    template<typename EventType>
    void onEvent(const EventType& event, const std::string& source, const std::string& fqn)
    {
        if (!listeners_.isEmpty()) {
            executorContext_.getCallbackExecutor().add([=]
                                                    {
                                                        boost::any anyEvent(event);
                                                        listeners_(anyEvent, source, fqn);
                                                    });
        }
    }

private:
    IEventManager&                           eventManager_;
    std::list<std::string>                   eventFQNs_;
    KaaObservable<void (const boost::any& value, const std::string& source, const std::string& fqn), RFIDEventCFListener*> listeners_;
    IExecutorContext& executorContext_;
    IKaaClientContext& context_;
};

}

#endif /* RFIDEventCF_HPP_ */