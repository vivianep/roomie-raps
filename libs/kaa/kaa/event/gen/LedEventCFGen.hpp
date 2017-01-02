/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef KAA_EVENT_GEN_LEDEVENTCFGEN_HPP_4263628908__H_
#define KAA_EVENT_GEN_LEDEVENTCFGEN_HPP_4263628908__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace nsLedEventCF {
struct LedEvent {
    bool isLighted;
    LedEvent() :
        isLighted(bool())
        { }
};

struct _LedEventCF_avsc_Union__0__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    LedEvent get_LedEvent() const;
    void set_LedEvent(const LedEvent& v);
    _LedEventCF_avsc_Union__0__();
};

inline
LedEvent _LedEventCF_avsc_Union__0__::get_LedEvent() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<LedEvent >(value_);
}

inline
void _LedEventCF_avsc_Union__0__::set_LedEvent(const LedEvent& v) {
    idx_ = 0;
    value_ = v;
}

inline _LedEventCF_avsc_Union__0__::_LedEventCF_avsc_Union__0__() : idx_(0), value_(LedEvent()) { }
}
namespace avro {
template<> struct codec_traits<nsLedEventCF::LedEvent> {
    static void encode(Encoder& e, const nsLedEventCF::LedEvent& v) {
        avro::encode(e, v.isLighted);
    }
    static void decode(Decoder& d, nsLedEventCF::LedEvent& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.isLighted);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.isLighted);
        }
    }
};

template<> struct codec_traits<nsLedEventCF::_LedEventCF_avsc_Union__0__> {
    static void encode(Encoder& e, nsLedEventCF::_LedEventCF_avsc_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_LedEvent());
            break;
        }
    }
    static void decode(Decoder& d, nsLedEventCF::_LedEventCF_avsc_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 1) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                nsLedEventCF::LedEvent vv;
                avro::decode(d, vv);
                v.set_LedEvent(vv);
            }
            break;
        }
    }
};

}
#endif
