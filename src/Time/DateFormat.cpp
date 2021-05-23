//
// Created by KyuubiRan on 2021/5/19.
//

#include "DateFormat.h"
#include "kstring.h"

using std::string;
using std::tm;

string kitsune::GetFormatDate(const string &fmt, const tm &timeInfo) {
    kstring sFmt = fmt;
    sFmt.sReplace("yyyy", 16, "%04d", timeInfo.tm_year + 1900)
            .sReplace("yy", 16, "%02d", timeInfo.tm_year % 100)
            .sReplace("MM", 16, "%02d", timeInfo.tm_mon + 1)
            .sReplace("M", 16, "%d", timeInfo.tm_mon + 1)
            .sReplace("dd", 16, "%02d", timeInfo.tm_mday)
            .sReplace("d", 16, "%d", timeInfo.tm_mday)
            .sReplace("HH", 16, "%02d", timeInfo.tm_hour)
            .sReplace("H", 16, "%d", timeInfo.tm_hour)
            .sReplace("hh", 16, "%02d", timeInfo.tm_hour > 12 ? timeInfo.tm_hour - 12 : timeInfo.tm_hour)
            .sReplace("h", 16, "%d", timeInfo.tm_hour > 12 ? timeInfo.tm_hour - 12 : timeInfo.tm_hour)
            .sReplace("mm", 16, "%02d", timeInfo.tm_min)
            .sReplace("m", 16, "%d", timeInfo.tm_min)
            .sReplace("ss", 16, "%02d", timeInfo.tm_sec)
            .sReplace("s", 16, "%d", timeInfo.tm_sec);
    return string(sFmt);
}