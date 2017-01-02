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


#ifndef KAA_EVENT_GEN_MOTIONEVENTCFGEN_HPP_4263628908__H_
#define KAA_EVENT_GEN_MOTIONEVENTCFGEN_HPP_4263628908__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace nsMotionEventCF {
struct MotionEvent {
    std::string timeTag;
    bool isPresent;
    MotionEvent() :
        timeTag(std::string()),
        isPresent(bool())
        { }
};

struct _MotionEventCF_avsc_Union__0__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    MotionEvent get_MotionEvent() const;
    void set_MotionEvent(const MotionEvent& v);
    _MotionEventCF_avsc_Union__0__();
};

inline
MotionEvent _MotionEventCF_avsc_Union__0__::get_MotionEvent() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MotionEvent >(value_);
}

inline
void _MotionEventCF_avsc_Union__0__::set_MotionEvent(const MotionEvent& v) {
    idx_ = 0;
    value_ = v;
}

inline _MotionEventCF_avsc_Union__0__::_MotionEventCF_avsc_Union__0__() : idx_(0), value_(MotionEvent()) { }
}
namespace avro {
template<> struct codec_traits<nsMotionEventCF::MotionEvent> {
    static void encode(Encoder& e, const nsMotionEventCF::MotionEvent& v) {
        avro::encode(e, v.timeTag);
        avro::encode(e, v.isPresent);
    }
    static void decode(Decoder& d, nsMotionEventCF::MotionEvent& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.timeTag);
                    break;
                case 1:
                    avro::decode(d, v.isPresent);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.timeTag);
            avro::decode(d, v.isPresent);
        }
    }
};

template<> struct codec_traits<nsMotionEventCF::_MotionEventCF_avsc_Union__0__> {
    static void encode(Encoder& e, nsMotionEventCF::_MotionEventCF_avsc_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_MotionEvent());
            break;
        }
    }
    static void decode(Decoder& d, nsMotionEventCF::_MotionEventCF_avsc_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 1) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                nsMotionEventCF::MotionEvent vv;
                avro::decode(d, vv);
                v.set_MotionEvent(vv);
            }
            break;
        }
    }
};

}
#endif
