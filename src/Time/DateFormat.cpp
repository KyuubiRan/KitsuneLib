//
// Created by KyuubiRan on 2021/5/19.
//

#include "DateFormat.h"
#include "../String/kstring.h"

using std::chrono::system_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::string;
using std::tm;

string kitsune::GetFormatDate(const string &fmt, const tm &timeinfo) {
    kstring sFmt = fmt;
    if (sFmt.contains("yyyy")) {
        sFmt.regexpReplace("yyyy", 16, "%04d", timeinfo.tm_year + 1900);
    }
    if (sFmt.contains("yy")) {
        sFmt.regexpReplace("yy", 16, "%02d", timeinfo.tm_year % 100);
    }
    if (sFmt.contains("MM")) {
        sFmt.regexpReplace("MM", 16, "%02d", timeinfo.tm_mon + 1);
    }
    if (sFmt.contains("dd")) {
        sFmt.regexpReplace("dd", 16, "%02d", timeinfo.tm_mday);
    }
    if (sFmt.contains("HH")) {
        sFmt.regexpReplace("HH", 16, "%02d", timeinfo.tm_hour);
    }
    if (sFmt.contains("hh")) {
        sFmt.regexpReplace("hh", 16, "%02d", timeinfo.tm_hour > 12 ? timeinfo.tm_hour - 12 : timeinfo.tm_hour);
    }
    if (sFmt.contains("mm")) {
        sFmt.regexpReplace("mm", 16, "%02d", timeinfo.tm_min);
    }
    if (sFmt.contains("ss")) {
        sFmt.regexpReplace("ss", 16, "%02d", timeinfo.tm_sec);
    }
    return string(sFmt);
}