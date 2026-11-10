#define _LIBCPP_ABI_ALTERNATE_STRING_LAYOUT 1
#include <string>
#include <filesystem>
#include <stdexcept>
#include <system_error>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

template class std::__1::basic_string<char>;
template class std::__1::basic_string<wchar_t>;

template std::__1::basic_string<char> std::__1::operator+<char, std::__1::char_traits<char>, std::__1::allocator<char>>(
    const char *, const std::__1::basic_string<char> &);
template std::__1::basic_string<char> std::__1::operator+<char, std::__1::char_traits<char>, std::__1::allocator<char>>(
    const std::__1::basic_string<char> &, const char *);
template std::__1::basic_string<char> std::__1::operator+<char, std::__1::char_traits<char>, std::__1::allocator<char>>(
    const std::__1::basic_string<char> &, const std::__1::basic_string<char> &);

namespace std::__1::__fs::filesystem {

path::__string_view path::__root_name() const {
  return __string_view();
}

path::__string_view path::__root_directory() const {
  if (!__pn_.empty() && __pn_[0] == '/')
    return __string_view(__pn_.data(), 1);
  return __string_view();
}

path::__string_view path::__root_path_raw() const {
  return __root_directory();
}

path::__string_view path::__filename() const {
  if (__pn_.empty())
    return __string_view();
  if (__pn_.size() == 1 && __pn_[0] == '/')
    return __string_view(__pn_.data(), 1);
  size_t last_slash = __pn_.rfind('/');
  if (last_slash == string_type::npos)
    return __string_view(__pn_.data(), __pn_.size());
  if (last_slash + 1 == __pn_.size())
    return __string_view();
  return __string_view(__pn_.data() + last_slash + 1, __pn_.size() - last_slash - 1);
}

path::__string_view path::__parent_path() const {
  if (__pn_.empty())
    return __string_view();
  size_t last_slash = __pn_.rfind('/');
  if (last_slash == string_type::npos)
    return __string_view();
  if (last_slash == 0)
    return __string_view(__pn_.data(), 1);
  return __string_view(__pn_.data(), last_slash);
}

path::__string_view path::__relative_path() const {
  if (__pn_.empty())
    return __string_view();
  if (__pn_[0] == '/') {
    size_t pos = __pn_.find_first_not_of('/');
    if (pos == string_type::npos)
      return __string_view();
    return __string_view(__pn_.data() + pos, __pn_.size() - pos);
  }
  return __string_view(__pn_.data(), __pn_.size());
}

int path::__compare(__string_view s) const {
  __string_view my_sv(__pn_.data(), __pn_.size());
  return my_sv.compare(s);
}

} // namespace std::__1::__fs::filesystem


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
string to_string(int val) {
  char buf[32];
  int n = ::snprintf(buf, sizeof(buf), "%d", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
}
string to_string(long val) {
  char buf[32];
  int n = ::snprintf(buf, sizeof(buf), "%ld", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
}
string to_string(long long val) {
  char buf[32];
  int n = ::snprintf(buf, sizeof(buf), "%lld", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
}
string to_string(unsigned val) {
  char buf[32];
  int n = ::snprintf(buf, sizeof(buf), "%u", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
}
string to_string(unsigned long val) {
  char buf[32];
  int n = ::snprintf(buf, sizeof(buf), "%lu", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
}
string to_string(unsigned long long val) {
  char buf[32];
  int n = ::snprintf(buf, sizeof(buf), "%llu", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
}
string to_string(float val) {
  char buf[128];
  int n = ::snprintf(buf, sizeof(buf), "%f", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
}
string to_string(double val) {
  char buf[384];
  int n = ::snprintf(buf, sizeof(buf), "%f", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
}
string to_string(long double val) {
  char buf[512];
  int n = ::snprintf(buf, sizeof(buf), "%Lf", val);
  if (n <= 0) return string();
  return string(buf, std::min<size_t>(n, sizeof(buf) - 1));
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
