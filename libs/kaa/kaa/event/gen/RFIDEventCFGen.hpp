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


#ifndef KAA_EVENT_GEN_RFIDEVENTCFGEN_HPP_4263628908__H_
#define KAA_EVENT_GEN_RFIDEVENTCFGEN_HPP_4263628908__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace nsRFIDEventCF {
struct RFIDEvent {
    std::string rfidId;
    std::string timeTag;
    RFIDEvent() :
        rfidId(std::string()),
        timeTag(std::string())
        { }
};

struct _RFIDEventCF_avsc_Union__0__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    RFIDEvent get_RFIDEvent() const;
    void set_RFIDEvent(const RFIDEvent& v);
    _RFIDEventCF_avsc_Union__0__();
};

inline
RFIDEvent _RFIDEventCF_avsc_Union__0__::get_RFIDEvent() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<RFIDEvent >(value_);
}

inline
void _RFIDEventCF_avsc_Union__0__::set_RFIDEvent(const RFIDEvent& v) {
    idx_ = 0;
    value_ = v;
}

inline _RFIDEventCF_avsc_Union__0__::_RFIDEventCF_avsc_Union__0__() : idx_(0), value_(RFIDEvent()) { }
}
namespace avro {
template<> struct codec_traits<nsRFIDEventCF::RFIDEvent> {
    static void encode(Encoder& e, const nsRFIDEventCF::RFIDEvent& v) {
        avro::encode(e, v.rfidId);
        avro::encode(e, v.timeTag);
    }
    static void decode(Decoder& d, nsRFIDEventCF::RFIDEvent& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.rfidId);
                    break;
                case 1:
                    avro::decode(d, v.timeTag);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.rfidId);
            avro::decode(d, v.timeTag);
        }
    }
};

template<> struct codec_traits<nsRFIDEventCF::_RFIDEventCF_avsc_Union__0__> {
    static void encode(Encoder& e, nsRFIDEventCF::_RFIDEventCF_avsc_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_RFIDEvent());
            break;
        }
    }
    static void decode(Decoder& d, nsRFIDEventCF::_RFIDEventCF_avsc_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 1) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                nsRFIDEventCF::RFIDEvent vv;
                avro::decode(d, vv);
                v.set_RFIDEvent(vv);
            }
            break;
        }
    }
};

}
#endif
