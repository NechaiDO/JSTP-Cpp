/*
The MIT License (MIT)

Copyright (c) 2016 Dmytro Nechai, Nikolai Belochub

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include "jsrs.h"

namespace jstp {

// JS_value implementation

bool JSRS::JS_value::bool_value() const { return false; }

double JSRS::JS_value::number_value() const { return 0; }

const string &JSRS::JS_value::string_value() const { return string(""); }

const array &JSRS::JS_value::array_items() const { return array(); }

const object &JSRS::JS_value::object_items() const { return object(); }

const JSRS &JSRS::JS_value::operator[](size_t i) const { return JSRS(); }

const JSRS &JSRS::JS_value::operator[](const std::string &key) const { return JSRS(); }
// end of JS_value implementation

// JS_number implementation

JSRS::JS_number::JS_number(double value) : value(value) { }

Type JSRS::JS_number::type() const { return JSRS::Type::NUMBER; }

bool JSRS::JS_number::equals(const JS_value *other) const {
  return other->type() == this->type() && this->number_value() == other->number_value();
}

bool JSRS::JS_number::less(const JS_value *other) const {
  return other->type() == this->type() && this->number_value() < other->number_value();
}

void JSRS::JS_number::dump(string &out) const { out = std::to_string(this->value); }

double JSRS::JS_number::number_value() const { return this->value; }
// end of JS_number implementation

// JS_boolean implementation

JSRS::JS_boolean::JS_boolean(bool value) : value(value) { }

Type JSRS::JS_boolean::type() const { return JSRS::Type::BOOL; }

bool JSRS::JS_boolean::equals(const JS_value *other) const {
  return other->type() == this->type() && this->bool_value() == other->bool_value();
}

bool JSRS::JS_boolean::less(const JS_value *other) const {
  return other->type() == this->type() && this->bool_value() < other->bool_value();
}

void JSRS::JS_boolean::dump(string &out) const { out = value ? "true" : "false"; }

bool JSRS::JS_boolean::bool_value() const { return value; }
// end of JS_boolean implementation

// JS_string implementation

JSRS::JS_string::JS_string(const string &value) : value(value) { }

Type JSRS::JS_string::type() const { return JSRS::Type::STRING; }

bool JSRS::JS_string::equals(const JS_value *other) const {
  return other->type() == this->type() && this->string_value().compare(other->string_value()) == 0;
}

bool JSRS::JS_string::less(const JS_value *other) const {
  return other->type() == this->type() && this->string_value().compare(other->string_value()) < 0;
}

void JSRS::JS_string::dump(string &out) const { out = value; }

const string &JSRS::JS_string::string_value() const { return value; }
// end of JS_string implementation
}


