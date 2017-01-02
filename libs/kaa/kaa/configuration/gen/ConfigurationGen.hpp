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


#ifndef CONFIGURATIONGEN_HPP_437739726__H_
#define CONFIGURATIONGEN_HPP_437739726__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace kaa_configuration {
struct _configuration_avsc_Union__0__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    boost::array<uint8_t, 16> get_uuidT() const;
    void set_uuidT(const boost::array<uint8_t, 16>& v);
    bool is_null() const {
        return (idx_ == 1);
    }
    void set_null() {
        idx_ = 1;
        value_ = boost::any();
    }
    _configuration_avsc_Union__0__();
};

struct Configuration {
    typedef _configuration_avsc_Union__0__ __uuid_t;
    __uuid_t __uuid;
    Configuration() :
        __uuid(__uuid_t())
        { }
};

inline
boost::array<uint8_t, 16> _configuration_avsc_Union__0__::get_uuidT() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<boost::array<uint8_t, 16> >(value_);
}

inline
void _configuration_avsc_Union__0__::set_uuidT(const boost::array<uint8_t, 16>& v) {
    idx_ = 0;
    value_ = v;
}

inline _configuration_avsc_Union__0__::_configuration_avsc_Union__0__() : idx_(0), value_(boost::array<uint8_t, 16>()) { }
}
namespace avro {
template<> struct codec_traits<kaa_configuration::_configuration_avsc_Union__0__> {
    static void encode(Encoder& e, kaa_configuration::_configuration_avsc_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_uuidT());
            break;
        case 1:
            e.encodeNull();
            break;
        }
    }
    static void decode(Decoder& d, kaa_configuration::_configuration_avsc_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                boost::array<uint8_t, 16> vv;
                avro::decode(d, vv);
                v.set_uuidT(vv);
            }
            break;
        case 1:
            d.decodeNull();
            v.set_null();
            break;
        }
    }
};

template<> struct codec_traits<kaa_configuration::Configuration> {
    static void encode(Encoder& e, const kaa_configuration::Configuration& v) {
        avro::encode(e, v.__uuid);
    }
    static void decode(Decoder& d, kaa_configuration::Configuration& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.__uuid);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.__uuid);
        }
    }
};

}
#endif
