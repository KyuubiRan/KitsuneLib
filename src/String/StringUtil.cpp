//
// Created by KyuubiRan on 2021/5/15.
//

#include "StringUtil.h"

using std::string;

string &kitsune::ToLowercase(string &str) {
    for (auto &c : str) {
        c = std::tolower(c);
    }
    return str;
}

string kitsune::ToLower(const string &str) {
    string s1 = str;
    for (auto &c : s1) {
        c = tolower(c);
    }
    return s1;
}

string &kitsune::ToUppercase(string &str) {
    for (auto &item : str) {
        item = std::toupper(item);
    }
    return str;
}

string kitsune::ToUpper(const string &str) {
    string s1 = str;
    for (auto &c : s1) {
        c = toupper(c);
    }
    return s1;
}

bool kitsune::StartsWith(const string &ori, const string &sub, bool ignoreCase) {
    string s1 = ori;
    string s2 = sub;
    if (ignoreCase) {
        ToLowercase(s1);
        ToLowercase(s2);
    }
    return s1.substr(0, s2.size()) == s2;
}

bool kitsune::EndsWith(const string &ori, const string &sub, bool ignoreCase) {
    string s1 = ori;
    string s2 = sub;
    if (ignoreCase) {
        ToLowercase(s1);
        ToLowercase(s2);
    }
    return s1.substr(s1.size() - s2.size()) == s2;
}

bool kitsune::Contains(const string &ori, const string &sub, bool ignoreCase) {
    string s1 = ori;
    string s2 = sub;
    if (ignoreCase) {
        ToLowercase(s1);
        ToLowercase(s2);
    }
    return s1.find(s2) != static_cast<size_t >(-1);
}

