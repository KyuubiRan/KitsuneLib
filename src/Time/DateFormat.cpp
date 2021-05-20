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
    sFmt.regexpReplace("yyyy", 16, "%04d", timeinfo.tm_year + 1900)
            .regexpReplace("yy", 16, "%02d", timeinfo.tm_year % 100)
            .regexpReplace("MM", 16, "%02d", timeinfo.tm_mon + 1)
            .regexpReplace("dd", 16, "%02d", timeinfo.tm_mday)
            .regexpReplace("HH", 16, "%02d", timeinfo.tm_hour)
            .regexpReplace("hh", 16, "%02d", timeinfo.tm_hour > 12 ? timeinfo.tm_hour - 12 : timeinfo.tm_hour)
            .regexpReplace("mm", 16, "%02d", timeinfo.tm_min)
            .regexpReplace("ss", 16, "%02d", timeinfo.tm_sec);
    return string(sFmt);
}