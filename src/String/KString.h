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

        inline KString &operator+=(const char ch) {
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
         * 查找字符串index
         * @param str string
         * @return index
         */
        using std::string::find;

        [[nodiscard]] inline size_t find(const KString &kStr) const { return std::string::find(kStr); }

        /**
         * @return 字符串长度
         */
        using std::string::size;

        using std::string::length;

        [[nodiscard]] inline bool isEmpty() const { return empty(); }

        [[nodiscard]] inline bool isNotEmpty() const { return !empty(); }

        /**
         * @return C风格字符串
         */
        [[nodiscard]] inline const char *toCString() const { return c_str(); }

        /**
         * @return std::string类型字符串
         */
        [[nodiscard]] const std::string &toString() const { return *this; }

        /**
         * 截取字符串 并返回新的对象
         * @param pos 起始位置
         * @param end 结束位置
         * @return 截取完后的新字符串
         */
        [[nodiscard]] inline KString substring(size_t pos = 0, size_t end = std::string::npos) const {
            return substr(pos, end);
        }

        /**
         * 查询字符串中是否包含指定字符
         * @param sub 查询的字符串
         * @param ignoreCase 忽略大小写
         * @return 是否包含
         */
        [[nodiscard]] bool contains(const std::string &sub, bool ignoreCase = false) const;

        [[nodiscard]] inline bool contains(const char szSub[], bool ignoreCase = false) const {
            return contains(std::string(szSub), ignoreCase);
        }

        /**
         * 查询字符串开头是否与指定字符串相同
         * @param sub 查询的字符串
         * @param ignoreCase 忽略大小写
         * @return 是否相同
         */
        [[nodiscard]] bool startswith(const std::string &sub, bool ignoreCase = false) const;

        [[nodiscard]] inline bool startswith(const char szSub[], bool ignoreCase = false) const {
            return startswith(std::string(szSub), ignoreCase);
        }

        /**
         * 查询字符串结尾是否与指定字符串相同
         * @param sub 查询的字符串
         * @param ignoreCase 忽略大小写
         * @return 是否相同
         */
        [[nodiscard]] bool endswith(const std::string &sub, bool ignoreCase = false) const;

        inline bool endswith(const char szSub[], bool ignoreCase = false) const {
            return endswith(std::string(szSub), ignoreCase);
        }

        /**
         * 替换字符串中的部分内容
         * @param ori 要替换的内容
         * @param sub 替换成
         * @return 自身引用
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
         * 使用sprintf替换字符串的部分内容
         * @param needReplacePart 需要替换的字符串
         * @paran bufSize buf大小
         * @param format 格式
         * @param ... 参数
         * @return 自身引用
         */
        KString &sReplace(const std::string &needReplacePart, size_t bufSize, const char *format, ...);

        /**
         * 使用sprintf格式化整个字符串
         * @param bufSize buf大小
         * @param format 格式
         * @param ... 参数
         * @return 自身引用
         */
        KString &sprintf(size_t bufSize, const char *format, ...);

        /**
         * 从指定位置开始替换字符串的内容
         * @param pos 起始位置
         * @param sub 替换成
         * @return 自身引用
         */
        inline KString &replace(size_t pos, const std::string &sub) {
            std::string::replace(pos, sub.size(), sub);
            return *this;
        }

        using std::string::replace;

        /**
         * 返回一个新的对象 并将字符串内容转化为小写
         * @return KString
         */
        [[nodiscard]] KString lowercase() const;

        /**
         * 返回一个新的对象 并将字符串内容转化为大写
         * @return KString
         */
        [[nodiscard]] KString uppercase() const;

        /**
         * 将自身字符串内容转化为小写 并返回自身引用
         * @return 自身引用
         */
        KString &toLowercase();

        /**
         * 将自身字符串内容转化为大写 并返回自身引用
         * @return 自身引用
         */
        KString &toUppercase();

        /**
         * 查询字符串出现的次数
         * @param sub string
         * @param ignoreCase 忽略大小写
         * @return 次数
         */
        [[nodiscard]] size_t queryOccurrenceTimes(const std::string &sub, bool ignoreCase = false) const;

        /**
         * 分割字符串
         * @param delim 分隔符
         * @param vKS KString向量
         * @return KString向量
         */
        std::vector<KString> &split(const std::string &delim, std::vector<KString> &vKS);

        inline std::vector<KString> splitString(const std::string &delim) {
            std::vector<KString> v;
            return split(delim, v);
        }

        /**
         * 读取整个文件流中的字符 返回KString对象
         * @param ifs ifstream
         * @return KString对象
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