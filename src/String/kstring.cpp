//
// Created by KyuubiRan on 2021/5/16.
//

#include <string>
#include "kstring.h"
#include "StringUtil.h"

using std::string;
using namespace kitsune;

kstring kstring::toLower() const {
    kstring tmp = *this;
    for (auto &c : tmp.mStr) {
        c = std::tolower(c);
    }
    return tmp;
}

kstring kstring::toUpper() const {
    kstring tmp = *this;
    for (auto &c :tmp.mStr) {
        c = std::toupper(c);
    }
    return tmp;
}

kstring &kstring::toLowercase() {
    for (auto &c : mStr) {
        c = std::tolower(c);
    }
    return *this;
}

kstring &kstring::toUppercase() {
    for (auto &c :mStr) {
        c = std::toupper(c);
    }
    return *this;
}

bool kstring::contains(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        ToLowercase(tmp);
        return this->toLower().find(tmp) != static_cast<size_t >(-1);
    }
    return this->find(sub) != static_cast<size_t >(-1);
}

bool kstring::startswith(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        ToLowercase(tmp);
        return this->toLower().substring(0, tmp.size()) == tmp;
    }
    return this->substring(0, sub.size()) == sub;
}

bool kstring::endswith(const string &sub, bool ignoreCase) const {
    if (ignoreCase) {
        string tmp = sub;
        ToLowercase(tmp);
        return this->toLower().substring(this->size() - tmp.size()) == tmp;
    }
    return this->substring(this->size() - sub.size()) == sub;
}

size_t kstring::queryOccurrenceTimes(const string &sub) const {
    return QueryOccurrenceTimes(this->mStr, sub);
}
