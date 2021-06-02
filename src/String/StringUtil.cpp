//
// Created by KyuubiRan on 2021/5/15.
//

#include "StringUtil.h"
#include <fstream>

using std::string;

string &kitsune::ToLowercase(string &str) {
    for (auto &c : str) {
        c = std::tolower(c); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    return str;
}

string kitsune::ToLower(const string &str) {
    string s1 = str;
    for (auto &c : s1) {
        c = std::tolower(c); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    return s1;
}

string &kitsune::ToUppercase(string &str) {
    for (auto &item : str) {
        item = std::toupper(item); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    return str;
}

string kitsune::ToUpper(const string &str) {
    string s1 = str;
    for (auto &c : s1) {
        c = std::toupper(c); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    return s1;
}

bool kitsune::StartsWith(const string &ori, const string &sub, bool ignoreCase) {
    string s1 = ori, s2 = sub;
    if (ignoreCase) {
        ToLowercase(s1);
        ToLowercase(s2);
    }
    return s1.substr(0, s2.size()) == s2;
}

bool kitsune::EndsWith(const string &ori, const string &sub, bool ignoreCase) {
    string s1 = ori, s2 = sub;
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

size_t kitsune::QueryOccurrenceTimes(const string &ori, const string &sub, bool ignoreCase) {
    if (ori.empty() || sub.empty()) return 0;
    string s1 = ori, s2 = sub;
    if (ignoreCase) {
        ToLowercase(s1);
        ToLowercase(s2);
    }
    size_t result = 0;
    size_t index = s1.find(s2);
    while (index != static_cast<size_t>(-1)) {
        ++result;
        if (index + s2.size() > s1.size()) return result;
        s1 = s1.substr(index + s2.size());
        index = s1.find(s2);
    }
    return result;
}

std::string kitsune::ReadText(std::ifstream &ifs) {
    return string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
}

