//
// Created by KyuubiRan on 2021/5/19.
//

#include "DateFormat.h"
#include "kstring.h"

using std::string;
using std::tm;

string kitsune::GetFormatDate(const string &fmt, const tm &timeinfo) {
    kstring sFmt = fmt;
    sFmt.sReplace("yyyy", 16, "%04d", timeinfo.tm_year + 1900)
            .sReplace("yy", 16, "%02d", timeinfo.tm_year % 100)
            .sReplace("MM", 16, "%02d", timeinfo.tm_mon + 1)
            .sReplace("dd", 16, "%02d", timeinfo.tm_mday)
            .sReplace("HH", 16, "%02d", timeinfo.tm_hour)
            .sReplace("hh", 16, "%02d", timeinfo.tm_hour > 12 ? timeinfo.tm_hour - 12 : timeinfo.tm_hour)
            .sReplace("mm", 16, "%02d", timeinfo.tm_min)
            .sReplace("ss", 16, "%02d", timeinfo.tm_sec);
    return string(sFmt);
}