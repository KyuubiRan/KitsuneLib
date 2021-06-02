//
// Created by KyuubiRan on 2021/5/16.
//

#include "KString.h"
#include <cstdarg>
#include <cstring>
#include <fstream>

using std::string;
using std::istreambuf_iterator;
using namespace kitsune;

KString KString::toLower() const {
    KString tmp = *this;
    for (auto &c : tmp.mStr) { c = std::tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return tmp;
}

KString KString::toUpper() const {
    KString tmp = *this;
    for (auto &c :tmp.mStr) { c = std::toupper(c); }// NOLINT(cppcoreguidelines-narrowing-conversions)
    return tmp;
}

KString &KString::toLowercase() {
    for (auto &c : this->mStr) { c = std::tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return *this;
}

KString &KString::toUppercase() {
    for (auto &c : this->mStr) { c = std::toupper(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
    return *this;
}

bool KString::contains(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return this->toLower().find(tmp) != static_cast<size_t >(-1);
    }
    return this->find(sub) != static_cast<size_t >(-1);
}

bool KString::startswith(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return this->toLower().substring(0, tmp.size()) == tmp;
    }
    return this->substring(0, sub.size()) == sub;
}

bool KString::endswith(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        for (auto &c : tmp) { c = tolower(c); } // NOLINT(cppcoreguidelines-narrowing-conversions)
        return this->toLower().substring(this->size() - tmp.size()) == tmp;
    }
    return this->substring(this->size() - sub.size()) == sub;
}

size_t KString::queryOccurrenceTimes(const string &sub, bool ignoreCase) const {
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

KString &KString::sReplace(const string &needReplacePart, size_t bufSize, const char *format, ...) {
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

KString &KString::sprintf(size_t bufSize, const char *format, ...) {
    char *buf = new char[bufSize];
    va_list args;
    va_start(args, format);
    vsprintf(buf, format, args);
    va_end(args);
    this->mStr = buf;
    delete[] buf;
    return *this;
}

std::vector<KString> &KString::splitString(const string &delim, std::vector<KString> &vKstr) {
    if (this->isEmpty() || delim.empty()) return vKstr;
    KString tmp = *this;
    size_t idx = tmp.find(delim);
    if (idx == INVALID_SIZE) {
        vKstr.push_back(tmp);
        return vKstr;
    }
    do {
        vKstr.push_back(tmp.substring(0, idx));
        tmp = tmp.substring(idx + delim.size());
        idx = tmp.find(delim);
    } while (idx != INVALID_SIZE);
    vKstr.push_back(tmp);
    return vKstr;
}

KString KString::ReadText(std::ifstream &ifs) {
    string str((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    return KString(str);
}
