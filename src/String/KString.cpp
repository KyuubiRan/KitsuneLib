//
// Created by KyuubiRan on 2021/5/16.
//

#include "KString.h"
#include <cstdarg>
#include <fstream>
#include <memory>

using std::string;
using std::istreambuf_iterator;
using namespace kitsune;

KString KString::lowercase() const {
    KString tmp = *this;
    for (auto &c : tmp) { c = std::tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return tmp;
}

KString KString::uppercase() const {
    KString tmp = *this;
    for (auto &c :tmp) { c = std::toupper(c); }// NOLINT(cppcoreguidelines-narrowing-conversions)
    return tmp;
}

KString &KString::toLowercase() {
    for (auto &c : *this) { c = std::tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return *this;
}

KString &KString::toUppercase() {
    for (auto &c : *this) { c = std::toupper(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return *this;
}

bool KString::contains(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return uppercase().find(tmp) != static_cast<size_t >(-1);
    }
    return find(sub) != static_cast<size_t >(-1);
}

bool KString::startswith(const string &sub, bool ignoreCase) const {
    if (!ignoreCase) {
        return std::string::starts_with(sub);
    } else {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return lowercase().toString().starts_with(tmp);
    }
}

bool KString::endswith(const string &sub, bool ignoreCase) const {
    if (!ignoreCase) {
        return std::string::ends_with(sub);
    } else {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return lowercase().toString().ends_with(tmp);
    }
}

size_t KString::queryOccurrenceTimes(const string &sub, bool ignoreCase) const {
    if (isEmpty() || sub.empty()) return 0;
    string s1 = *this, s2 = sub;
    if (ignoreCase) {
        for (auto &c : s1) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        for (auto &c : s2) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    size_t result = 0;
    size_t index = s1.find(s2);
    while (index != std::string::npos) {
        ++result;
        if (index + s2.size() > s1.size()) return result;
        s1 = s1.substr(index + s2.size());
        index = s1.find(s2);
    }
    return result;
}

KString &KString::sReplace(const string &needReplacePart, size_t bufSize, const char *format, ...) {
    if (!contains(needReplacePart)) return *this;
    auto upBuf = std::unique_ptr<char[]>(new char[bufSize]);
    va_list args;
    va_start(args, format);
    vsprintf(upBuf.get(), format, args);
    va_end(args);
    replace(needReplacePart, upBuf.get());
    return *this;
}

KString &KString::sprintf(size_t bufSize, const char *format, ...) {
    auto upBuf = std::unique_ptr<char[]>(new char[bufSize]);
    va_list args;
    va_start(args, format);
    vsprintf(upBuf.get(), format, args);
    va_end(args);
    *this = upBuf.get();
    return *this;
}

std::vector<KString> &KString::split(const string &delim, std::vector<KString> &vKS) {
    if (isEmpty() || delim.empty()) return vKS;
    KString tmp = *this;
    size_t idx = tmp.find(delim);
    if (idx == std::string::npos) {
        vKS.push_back(tmp);
        return vKS;
    }
    do {
        vKS.push_back(tmp.substring(0, idx));
        tmp = tmp.substring(idx + delim.size());
        idx = tmp.find(delim);
    } while (idx != std::string::npos);
    vKS.push_back(tmp);
    return vKS;
}

KString KString::readText(std::ifstream &ifs) {
    string str((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    return KString(str);
}
