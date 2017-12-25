#ifndef HPS_H_
#define HPS_H_

#include <iostream>
#include <sstream>
#include "basic_types/basic_types.h"
#include "containers/containers.h"
#include "serializer.h"

namespace hps {
template <class T>
void serialize(const T& t, std::ostream& stream) {
  OutputBuffer ob(stream);
  Serializer<T>::serialize(t, ob);
  ob.flush();
}

template <class T>
void parse(T& t, std::istream& stream) {
  InputBuffer ib(stream);
  Serializer<T>::parse(t, ib);
}

template <class T>
T parse(std::istream& stream) {
  T t;
  parse<T>(t, stream);
  return t;
}

template <class T>
void serialize_to_string(const T& t, std::string& str) {
  std::stringstream ss;
  serialize(t, ss);
  str = ss.str();
}

template <class T>
std::string serialize_to_string(const T& t) {
  std::string str;
  serialize_to_string(t, str);
  return str;
}

template <class T>
void parse_from_string(T& t, const std::string& str) {
  std::stringstream ss(str);
  parse(t, ss);
}

template <class T>
T parse_from_string(const std::string& str) {
  T t;
  parse_from_string<T>(t, str);
  return t;
}

}  // namespace hps

#endif