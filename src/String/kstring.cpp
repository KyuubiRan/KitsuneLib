//
// Created by KyuubiRan on 2021/5/16.
//

#include "kstring.h"
#include <cstdarg>
#include <cstring>

using std::string;
using namespace kitsune;

kstring kstring::toLower() const {
    kstring tmp = *this;
    for (auto &c : tmp.mStr) { c = std::tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return tmp;
}

kstring kstring::toUpper() const {
    kstring tmp = *this;
    for (auto &c :tmp.mStr) { c = std::toupper(c); }// NOLINT(cppcoreguidelines-narrowing-conversions)
    return tmp;
}

kstring &kstring::toLowercase() {
    for (auto &c : this->mStr) { c = std::tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return *this;
}

kstring &kstring::toUppercase() {
    for (auto &c : this->mStr) { c = std::toupper(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return *this;
}

bool kstring::contains(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return this->toLower().find(tmp) != static_cast<size_t >(-1);
    }
    return this->find(sub) != static_cast<size_t >(-1);
}

bool kstring::startswith(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return this->toLower().substring(0, tmp.size()) == tmp;
    }
    return this->substring(0, sub.size()) == sub;
}

bool kstring::endswith(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return this->toLower().substring(this->size() - tmp.size()) == tmp;
    }
    return this->substring(this->size() - sub.size()) == sub;
}

size_t kstring::queryOccurrenceTimes(const string &sub, bool ignoreCase) const {
    if (this->isEmpty() || sub.empty()) return 0;
    string s1 = this->mStr, s2 = sub;
    if (ignoreCase) {
        for (auto &c : s1) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        for (auto &c : s2) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    size_t result = 0;
    size_t index = s1.find(s2);
    while (index != INVALID_SIZE) {
        ++result;
        if (index + s2.size() > s1.size()) return result;
        s1 = s1.substr(index + s2.size());
        index = s1.find(s2);
    }
    return result;
}

kstring &kstring::sReplace(const string &needReplacePart, size_t bufSize, const char *format, ...) {
    if (!this->contains(needReplacePart)) return *this;
    char *buf = new char[bufSize];
    va_list args;
    va_start(args, format);
    vsprintf(buf, format, args);
    va_end(args);
    this->replace(needReplacePart, buf);
    delete[] buf;
    return *this;
}

kstring &kstring::sprintf(size_t bufSize, const char *format, ...) {
    char *buf = new char[bufSize];
    va_list args;
    va_start(args, format);
    vsprintf(buf, format, args);
    va_end(args);
    this->mStr = buf;
    delete[] buf;
    return *this;
}

std::vector<kstring> &kstring::splitString(const string &delim, std::vector<kstring> &vKstr) {
    if (this->isEmpty() || delim.empty()) return vKstr;
    string tmp = *this;
    char *p = std::strtok(const_cast<char *>(tmp.c_str()), delim.c_str());
    while (p) {
        tmp = p;
        vKstr.emplace_back(tmp);
        p = std::strtok(nullptr, delim.c_str());
    }
    return vKstr;
}