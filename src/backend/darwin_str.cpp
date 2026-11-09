#define _LIBCPP_ABI_ALTERNATE_STRING_LAYOUT 1
#include <string>
#include <stdexcept>
#include <system_error>
#include <cstdlib>

template class std::__1::basic_string<char>;
template class std::__1::basic_string<wchar_t>;

namespace std::__1 {
double stod(const string &__str, size_t *__idx) {
  char *end = nullptr;
  double res = ::strtod(__str.c_str(), &end);
  if (__idx) *__idx = end - __str.c_str();
  return res;
}
float stof(const string &__str, size_t *__idx) {
  char *end = nullptr;
  float res = ::strtof(__str.c_str(), &end);
  if (__idx) *__idx = end - __str.c_str();
  return res;
}
int stoi(const string &__str, size_t *__idx, int __base) {
  char *end = nullptr;
  long res = ::strtol(__str.c_str(), &end, __base);
  if (__idx) *__idx = end - __str.c_str();
  return static_cast<int>(res);
}
long stol(const string &__str, size_t *__idx, int __base) {
  char *end = nullptr;
  long res = ::strtol(__str.c_str(), &end, __base);
  if (__idx) *__idx = end - __str.c_str();
  return res;
}
long long stoll(const string &__str, size_t *__idx, int __base) {
  char *end = nullptr;
  long long res = ::strtoll(__str.c_str(), &end, __base);
  if (__idx) *__idx = end - __str.c_str();
  return res;
}
unsigned long stoul(const string &__str, size_t *__idx, int __base) {
  char *end = nullptr;
  unsigned long res = ::strtoul(__str.c_str(), &end, __base);
  if (__idx) *__idx = end - __str.c_str();
  return res;
}
unsigned long long stoull(const string &__str, size_t *__idx, int __base) {
  char *end = nullptr;
  unsigned long long res = ::strtoull(__str.c_str(), &end, __base);
  if (__idx) *__idx = end - __str.c_str();
  return res;
}
}

extern "C" {
void __ZNSt11logic_errorC1ERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE(
    std::logic_error *self, const std::__1::string &msg) {
  new (self) std::logic_error(msg.c_str());
}
void __ZNSt11logic_errorC2ERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE(
    std::logic_error *self, const std::__1::string &msg) {
  new (self) std::logic_error(msg.c_str());
}
void __ZNSt13runtime_errorC1ERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE(
    std::runtime_error *self, const std::__1::string &msg) {
  new (self) std::runtime_error(msg.c_str());
}
void __ZNSt13runtime_errorC2ERKNSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE(
    std::runtime_error *self, const std::__1::string &msg) {
  new (self) std::runtime_error(msg.c_str());
}
void __ZNSt3__112system_errorC2ENS_10error_codeERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE(
    std::__1::system_error *self, std::__1::error_code ec, const std::__1::string &what) {
  new (self) std::__1::system_error(ec, what.c_str());
}
}
