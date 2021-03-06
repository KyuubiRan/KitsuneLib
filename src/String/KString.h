//
// Created by KyuubiRan on 2021/5/16.
//

#ifndef KITSUNELIB_KSTRING_H
#define KITSUNELIB_KSTRING_H

#include <string>
#include <bits/move.h>
#include <utility>
#include <vector>

namespace kitsune {

    class KString : private std::string {
    private:
        friend inline std::ostream &operator<<(std::ostream &os, const KString &ks);

        friend inline std::istream &operator>>(std::istream &is, KString &ks);

    public:
        inline KString() : std::string() {}

        inline KString(const char sz[]) : std::string(sz) {} // NOLINT(google-explicit-constructor)

        inline KString(std::string str) noexcept: std::string(std::move(str)) {} // NOLINT(google-explicit-constructor)

        inline operator const char *() const { return c_str(); } // NOLINT(google-explicit-constructor)

        using std::string::compare;

        using std::string::iterator;
        using std::string::const_iterator;

        using std::string::reverse_iterator;
        using std::string::const_reverse_iterator;

        using std::string::begin;

        using std::string::end;

        using std::string::cbegin;

        using std::string::cend;

        using std::string::rbegin;

        using std::string::rend;

        using std::string::crbegin;

        using std::string::crend;

        inline KString &operator+=(const KString &ks) {
            std::string::operator+=(ks);
            return *this;
        }

        inline bool operator==(const KString &ks) const {
            return this->toString() == ks.toString();
        }

        inline bool operator==(const std::string &str) const {
            return toString() == str;
        }

        inline bool operator==(const char sz[]) const {
            return toString() == sz;
        }

        inline bool operator>=(const KString &ks) const {
            return this->toString() >= ks.toString();
        }

        inline bool operator>=(const std::string &str) const {
            return toString() >= str;
        }

        inline bool operator>=(const char sz[]) const {
            return toString() >= sz;
        }

        inline bool operator<=(const KString &ks) const {
            return this->toString() <= ks.toString();
        }

        inline bool operator<=(const std::string &str) const {
            return toString() <= str;
        }

        inline bool operator<=(const char sz[]) const {
            return toString() <= sz;
        }

        inline bool operator>(const KString &ks) const {
            return this->toString() > ks.toString();
        }

        inline bool operator>(const std::string &str) const {
            return toString() > str;
        }

        inline bool operator>(const char sz[]) const {
            return toString() > sz;
        }

        inline bool operator<(const KString &ks) const {
            return this->toString() < ks.toString();
        }

        inline bool operator<(const std::string &str) const {
            return toString() < str;
        }

        inline bool operator<(const char sz[]) const {
            return toString() < sz;
        }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"

        inline KString &operator+=(const std::string &s) {
            std::string::operator+=(s);
            return *this;
        }

        inline KString &operator+=(const char sz[]) {
            std::string::operator+=(sz);
            return *this;
        }

        inline KString &operator+=(char ch) {
            std::string::operator+=(ch);
            return *this;
        }

        inline KString &append(const char sz[]) {
            std::string::append(sz);
            return *this;
        }

        inline KString &append(const std::string &s) {
            std::string::append(s);
            return *this;
        }

#pragma clang diagnostic pop

        inline KString &append(const KString &ks) {
            std::string::append(ks);
            return *this;
        }

        inline KString &append(char ch) {
            std::string::append(std::to_string(ch));
            return *this;
        }

        inline KString &append(short sh) {
            std::string::append(std::to_string(sh));
            return *this;
        }

        inline KString &append(int i) {
            std::string::append(std::to_string(i));
            return *this;
        }

        inline KString &append(unsigned ui) {
            std::string::append(std::to_string(ui));
            return *this;
        }

        inline KString &append(long l) {
            std::string::append(std::to_string(l));
            return *this;
        }

        inline KString &append(unsigned long ul) {
            std::string::append(std::to_string(ul));
            return *this;
        }

        inline KString &append(long long ll) {
            std::string::append(std::to_string(ll));
            return *this;
        }

        inline KString &append(unsigned long long ull) {
            std::string::append(std::to_string(ull));
            return *this;
        }

        inline KString &append(double d) {
            std::string::append(std::to_string(d));
            return *this;
        }

        inline KString &append(long double ld) {
            std::string::append(std::to_string(ld));
            return *this;
        }

        inline KString &append(float f) {
            std::string::append(std::to_string(f));
            return *this;
        }

        /**
         * ???????????????index
         * @param str string
         * @return index
         */
        using std::string::find;

        [[nodiscard]] inline size_t find(const KString &kStr) const { return std::string::find(kStr); }

        /**
         * @return ???????????????
         */
        using std::string::size;

        using std::string::length;

        [[nodiscard]] inline bool isEmpty() const { return empty(); }

        [[nodiscard]] inline bool isNotEmpty() const { return !empty(); }

        /**
         * @return C???????????????
         */
        [[nodiscard]] inline const char *toCString() const { return c_str(); }

        /**
         * @return std::string???????????????
         */
        [[nodiscard]] const std::string &toString() const { return *this; }

        /**
         * ??????????????? ?????????????????????
         * @param pos ????????????
         * @param end ????????????
         * @return ???????????????????????????
         */
        [[nodiscard]] inline KString substring(size_t pos = 0, size_t end = std::string::npos) const {
            return substr(pos, end);
        }

        /**
         * ??????????????????????????????????????????
         * @param sub ??????????????????
         * @param ignoreCase ???????????????
         * @return ????????????
         */
        [[nodiscard]] bool contains(const std::string &sub, bool ignoreCase = false) const;

        [[nodiscard]] inline bool contains(const char szSub[], bool ignoreCase = false) const {
            return contains(std::string(szSub), ignoreCase);
        }

        /**
         * ???????????????????????????????????????????????????
         * @param sub ??????????????????
         * @param ignoreCase ???????????????
         * @return ????????????
         */
        [[nodiscard]] bool startswith(const std::string &sub, bool ignoreCase = false) const;

        [[nodiscard]] inline bool startswith(const char szSub[], bool ignoreCase = false) const {
            return startswith(std::string(szSub), ignoreCase);
        }

        /**
         * ???????????????????????????????????????????????????
         * @param sub ??????????????????
         * @param ignoreCase ???????????????
         * @return ????????????
         */
        [[nodiscard]] bool endswith(const std::string &sub, bool ignoreCase = false) const;

        inline bool endswith(const char szSub[], bool ignoreCase = false) const {
            return endswith(std::string(szSub), ignoreCase);
        }

        /**
         * ?????????????????????????????????
         * @param ori ??????????????????
         * @param sub ?????????
         * @return ????????????
         */
        inline KString &replace(const std::string &ori, const std::string &sub) {
            size_t idx = std::string::find(ori);
            if (idx != std::string::npos) std::string::replace(idx, ori.size(), sub);
            return *this;
        }

        inline KString &replace(const std::string &ori, size_t n, const char szSub[]) {
            size_t idx = std::string::find(ori);
            if (idx != std::string::npos) replace(idx, n, szSub);
            return *this;
        }

        inline KString &replace(const char szOri[], size_t n, const char szSub[]) {
            size_t idx = std::string::find(szOri);
            if (idx != std::string::npos) std::string::replace(idx, n, szSub);
            return *this;
        }

        inline KString &replace(const char szOri[], const std::string &sub) {
            return replace(std::string(szOri), sub);
        }

        /**
         * ??????sprintf??????????????????????????????
         * @param needReplacePart ????????????????????????
         * @paran bufSize buf??????
         * @param format ??????
         * @param ... ??????
         * @return ????????????
         */
        KString &sReplace(const std::string &needReplacePart, size_t bufSize, const char *format, ...);

        /**
         * ??????sprintf????????????????????????
         * @param bufSize buf??????
         * @param format ??????
         * @param ... ??????
         * @return ????????????
         */
        KString &sprintf(size_t bufSize, const char *format, ...);

        /**
         * ?????????????????????????????????????????????
         * @param pos ????????????
         * @param sub ?????????
         * @return ????????????
         */
        inline KString &replace(size_t pos, const std::string &sub) {
            std::string::replace(pos, sub.size(), sub);
            return *this;
        }

        using std::string::replace;

        /**
         * ???????????????????????? ????????????????????????????????????
         * @return KString
         */
        [[nodiscard]] KString lowercase() const;

        /**
         * ???????????????????????? ????????????????????????????????????
         * @return KString
         */
        [[nodiscard]] KString uppercase() const;

        /**
         * ??????????????????????????????????????? ?????????????????????
         * @return ????????????
         */
        KString &toLowercase();

        /**
         * ??????????????????????????????????????? ?????????????????????
         * @return ????????????
         */
        KString &toUppercase();

        /**
         * ??????????????????????????????
         * @param sub string
         * @param ignoreCase ???????????????
         * @return ??????
         */
        [[nodiscard]] size_t queryOccurrenceTimes(const std::string &sub, bool ignoreCase = false) const;

        /**
         * ???????????????
         * @param delim ?????????
         * @param vKS KString??????
         * @return KString??????
         */
        std::vector<KString> &split(const std::string &delim, std::vector<KString> &vKS);

        inline std::vector<KString> splitString(const std::string &delim) {
            std::vector<KString> v;
            return split(delim, v);
        }

        /**
         * ????????????????????????????????? ??????KString??????
         * @param ifs ifstream
         * @return KString??????
         */
        static KString readText(std::ifstream &ifs);
    };

    inline std::ostream &operator<<(std::ostream &os, const KString &ks) {
        return os << (std::string &) ks;
    }

    inline std::istream &operator>>(std::istream &is, KString &ks) {
        is >> (std::string &) ks;
        return is;
    }
}

#endif //KITSUNELIB_KSTRING_H