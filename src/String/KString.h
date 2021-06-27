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

    class KString {
    private:
        std::string mStr;

        friend inline std::ostream &operator<<(std::ostream &os, const KString &ks);

        friend inline std::istream &operator>>(std::istream &is, KString &ks);

    public:
        inline KString() : mStr() {}

        inline KString(const char sz[]) : mStr(sz) {} // NOLINT(google-explicit-constructor)

        inline KString(std::string str) noexcept: mStr(std::move(str)) {} // NOLINT(google-explicit-constructor)

        inline KString(std::string &&str) noexcept: mStr(str) {} // NOLINT(google-explicit-constructor)

        inline operator const std::string &() const { return mStr; } // NOLINT(google-explicit-constructor)

        inline operator const char *() const { return mStr.c_str(); } // NOLINT(google-explicit-constructor)

        /**
         * 比较字符串
         * @param str string
         * @return 结果
         */
        [[nodiscard]] inline bool equals(const std::string &str) const { return mStr == str; }

        [[nodiscard]] inline bool equals(const char sz[]) const { return mStr == sz; }

        [[nodiscard]] inline bool operator==(const std::string &str) const { return equals(str); }

        [[nodiscard]] inline bool operator==(const char sz[]) const { return equals(sz); }

        [[nodiscard]] inline bool operator<(const std::string &str) const { return mStr < str; }

        [[nodiscard]] inline bool operator<=(const std::string &str) const { return mStr <= str; }

        [[nodiscard]] inline bool operator<(const char sz[]) const { return mStr < sz; }

        [[nodiscard]] inline bool operator<=(const char sz[]) const { return mStr <= sz; }

        [[nodiscard]] inline bool operator>(const std::string &str) const { return mStr > str; }

        [[nodiscard]] inline bool operator>=(const std::string &str) const { return mStr >= str; }

        [[nodiscard]] inline bool operator>(const char sz[]) const { return mStr > sz; }

        [[nodiscard]] inline bool operator>=(const char sz[]) const { return mStr >= sz; }

        [[nodiscard]] inline bool operator!=(const std::string &str) const { return mStr != str; }

        [[nodiscard]] inline bool operator!=(const char sz[]) const { return mStr != sz; }

        /**
         * 操作字符串
         * @param s 字符串
         * @return 自身
         */
        inline KString &operator=(const std::string &s) {
            mStr = s;
            return *this;
        }

        inline KString &operator=(const char sz[]) {
            mStr = sz;
            return *this;
        }

        inline KString &operator=(const char ch) {
            mStr = ch;
            return *this;
        }

        inline KString &operator+=(const std::string &s) {
            mStr += s;
            return *this;
        }

        inline KString &operator+=(const char sz[]) {
            mStr += sz;
            return *this;
        }

        inline KString &operator+=(const char ch) {
            mStr += ch;
            return *this;
        }

        [[nodiscard]] inline std::string::iterator begin() { return mStr.begin(); }

        [[nodiscard]] inline std::string::iterator end() { return mStr.end(); }

        [[nodiscard]] inline std::string::const_iterator cbegin() const noexcept { return mStr.cbegin(); }

        [[nodiscard]] inline std::string::const_iterator cend() const noexcept { return mStr.cend(); }

        [[nodiscard]] inline std::string::reverse_iterator rbegin() { return mStr.rbegin(); }

        [[nodiscard]] inline std::string::reverse_iterator rend() { return mStr.rend(); }

        [[nodiscard]] inline std::string::const_reverse_iterator
        crbegin() const noexcept { return mStr.crbegin(); }

        [[nodiscard]] inline std::string::const_reverse_iterator
        crend() const noexcept { return mStr.crend(); }

        inline KString &operator=(const KString &s) = default;

        /**
         * 拼接字符串
         * @param str string
         * @return 自身引用
         */
        inline KString &append(const std::string &str) {
            mStr.append(str);
            return *this;
        }

        inline KString &append(const char sz[]) {
            mStr.append(sz);
            return *this;
        }

        inline KString &append(char ch) {
            mStr.append(std::to_string(ch));
            return *this;
        }

        inline KString &append(short sh) {
            mStr.append(std::to_string(sh));
            return *this;
        }

        inline KString &append(int i) {
            mStr.append(std::to_string(i));
            return *this;
        }

        inline KString &append(unsigned ui) {
            mStr.append(std::to_string(ui));
            return *this;
        }

        inline KString &append(long long int ll) {
            mStr.append(std::to_string(ll));
            return *this;
        }

        inline KString &append(unsigned long long int ull) {
            mStr.append(std::to_string(ull));
            return *this;
        }

        inline KString &append(double d) {
            mStr.append(std::to_string(d));
            return *this;
        }

        inline KString &append(long double ld) {
            mStr.append(std::to_string(ld));
            return *this;
        }

        inline KString &append(float f) {
            mStr.append(std::to_string(f));
            return *this;
        }

        /**
         * 查找字符串index
         * @param str string
         * @return index
         */
        [[nodiscard]] inline size_t find(const std::string &str) const { return mStr.find(str); }

        [[nodiscard]] inline size_t find(const KString &kStr) const { return mStr.find(kStr.mStr); }

        [[nodiscard]] inline size_t find(const char sz[]) const { return mStr.find(sz); }

        [[nodiscard]] inline size_t find(const char ch) const { return mStr.find(ch); }

        /**
         * @return 字符串长度
         */
        [[nodiscard]] inline size_t size() const { return mStr.size(); }

        [[nodiscard]] inline size_t length() const { return mStr.length(); }

        [[nodiscard]] inline bool isEmpty() const { return mStr.empty(); }

        [[nodiscard]] inline bool isNotEmpty() const { return !mStr.empty(); }

        /**
         * @return C风格字符串
         */
        [[nodiscard]] inline const char *toCString() const { return mStr.c_str(); }

        /**
         * 截取字符串 并返回新的对象
         * @param pos 起始位置
         * @param end 结束位置
         * @return 截取完后的新字符串
         */
        [[nodiscard]] inline KString substring(size_t pos = 0, size_t end = std::string::npos) const {
            return KString(mStr.substr(pos, end));
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
            size_t idx = mStr.find(ori);
            if (idx != std::string::npos) mStr.replace(idx, ori.size(), sub);
            return *this;
        }

        inline KString &replace(const std::string &ori, size_t n, const char szSub[]) {
            size_t idx = mStr.find(ori);
            if (idx != std::string::npos) mStr.replace(idx, n, szSub);
            return *this;
        }

        inline KString &replace(const char szOri[], size_t n, const char szSub[]) {
            size_t idx = mStr.find(szOri);
            if (idx != std::string::npos) mStr.replace(idx, n, szSub);
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
            mStr.replace(pos, sub.size(), sub);
            return *this;
        }

        /**
         * 从指定位置开始替换字符串的内容
         * @param pos 起始位置
         * @param n 大小
         * @param szSub 替换成
         * @return 自身引用
         */
        inline KString &replace(size_t pos, size_t n, const char szSub[]) {
            mStr.replace(pos, n, szSub);
            return *this;
        }

        /**
         * 返回一个新的对象 并将字符串内容转化为小写
         * @return KString
         */
        [[nodiscard]] KString toLower() const;

        /**
         * 返回一个新的对象 并将字符串内容转化为大写
         * @return KString
         */
        [[nodiscard]] KString toUpper() const;

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
         * @param vKstr KString向量
         * @return KString向量
         */
        std::vector<KString> &splitString(const std::string &delim, std::vector<KString> &vKstr);

        /**
         * 读取整个文件流中的字符 返回KString对象
         * @param ifs ifstream
         * @return KString对象
         */
        static KString ReadText(std::ifstream &ifs);
    };

    /**
     * 往流内写入字符串
     * @param os ostream
     * @param ks KString
     * @return ostream
     */
    inline std::ostream &operator<<(std::ostream &os, const KString &ks) { return os << ks.mStr; }

    /**
     * 从流内读取字符串
     * @param is istream
     * @param ks KString
     * @return istream
     */
    inline std::istream &operator>>(std::istream &is, KString &ks) { return is >> ks.mStr; }
}

#endif //KITSUNELIB_KSTRING_H