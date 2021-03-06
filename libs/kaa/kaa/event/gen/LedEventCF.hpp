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

#ifndef LedEventCF_HPP_
#define LedEventCF_HPP_


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

#include "kaa/event/gen/LedEventCFGen.hpp"

namespace kaa {

class LedEventCF : public IEventFamily
{
public:
    class LedEventCFListener
    {
    public:

                virtual void onEvent(const nsLedEventCF :: LedEvent& event, const std::string& source) = 0;


        virtual ~LedEventCFListener() {}
    };

public:
    LedEventCF(IEventManager& manager, IKaaClientContext &context)
        : eventManager_(manager), executorContext_(context.getExecutorContext()), context_(context)
    {
        eventFQNs_ =         {"com.roomie.led.LedEvent"} /* {"fqn1","fqn2","fqn3"} */;
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

                if (fqn == "com.roomie.led.LedEvent") {
            nsLedEventCF :: LedEvent event;
            AvroByteArrayConverter< nsLedEventCF :: LedEvent > converter;
            converter.fromByteArray(data.data(), data.size(), event);
            onEvent(event, source, fqn);
        }


    }

    

    virtual const FQNList& getSupportedEventClassFQNs()
    {
        return eventFQNs_;
    }

    void addEventFamilyListener(LedEventCFListener& listener)
    {
        LedEventCFListener *listenerPtr = &listener;
        listeners_.addCallback(listenerPtr, [listenerPtr](const boost::any& value, const std::string& source, const std::string& fqn) {
                    if (fqn == "com.roomie.led.LedEvent") {
            auto event(boost::any_cast<nsLedEventCF :: LedEvent>(value));
            listenerPtr->onEvent(event, source);
        }

        });
    }

    void removeEventFamilyListener(LedEventCFListener& listener)
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
    KaaObservable<void (const boost::any& value, const std::string& source, const std::string& fqn), LedEventCFListener*> listeners_;
    IExecutorContext& executorContext_;
    IKaaClientContext& context_;
};

}

#endif /* LedEventCF_HPP_ */