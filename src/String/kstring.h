//
// Created by KyuubiRan on 2021/5/16.
//

#ifndef KITSUNELIB_KSTRING_H
#define KITSUNELIB_KSTRING_H

#include <string>
#include <bits/move.h>

namespace kitsune {

    class kstring {
    private:
        std::string mStr;

        friend inline std::ostream &operator<<(std::ostream &os, const kstring &ks);

        friend inline std::istream &operator>>(std::istream &is, kstring &ks);

    public:
        inline kstring() : mStr() {}

        inline kstring(const char sz[]) : mStr(sz) {} // NOLINT(google-explicit-constructor)

        inline kstring(std::string str) : mStr(std::move(str)) {} // NOLINT(google-explicit-constructor)

        inline explicit operator const std::string &() const { return this->mStr; }

        /**
         * 比较字符串是否相等
         * @param str string
         * @return 是否相等
         */
        [[nodiscard]] inline bool equals(const std::string &str) const { return this->mStr == str; }

        [[nodiscard]] inline bool equals(const char sz[]) const { return this->mStr == sz; }

        [[nodiscard]] inline bool operator==(const std::string &str) const { return this->equals(str); }

        [[nodiscard]] inline bool operator==(const char sz[]) const { return this->equals(sz); }

        inline kstring &operator=(const std::string &s) {
            this->mStr = s;
            return *this;
        }

        inline kstring &operator=(const kstring &s) = default;

        /**
         * 拼接字符串
         * @param str string
         * @return 自身引用
         */
        inline kstring &append(const std::string &str) {
            this->mStr.append(str);
            return *this;
        }

        inline kstring &append(const char sz[]) {
            this->mStr.append(sz);
            return *this;
        }

        /**
         * 查找字符串index
         * @param str string
         * @return index
         */
        [[nodiscard]] inline size_t find(const std::string &str) const { return this->mStr.find(str); }

        [[nodiscard]] inline size_t find(const kstring &kStr) const { return this->mStr.find(kStr.mStr); }

        [[nodiscard]] inline size_t find(const char sz[]) const { return this->mStr.find(sz); }

        [[nodiscard]] inline size_t find(const char ch) const { return this->mStr.find(ch); }

        /**
         * @return 字符串长度
         */
        [[nodiscard]] inline size_t size() const { return this->mStr.size(); }

        [[nodiscard]] inline size_t length() const { return this->mStr.length(); }

        [[nodiscard]] inline bool isEmpty() const { return this->mStr.empty(); }

        [[nodiscard]] inline bool isNotEmpty() const { return !this->mStr.empty(); }

        /**
         * @return C风格字符串
         */
        [[nodiscard]] inline const char *toCString() const { return this->mStr.c_str(); }

        /**
         * 截取字符串 并返回新的对象
         * @param pos 起始位置
         * @param end 结束位置
         * @return 截取完后的新字符串
         */
        [[nodiscard]] inline kstring substring(size_t pos = 0, size_t end = static_cast<size_t>(-1)) const {
            return kstring(this->mStr.substr(pos, end));
        }

        /**
         * 查询字符串中是否包含指定字符
         * @param sub 查询的字符串
         * @param ignoreCase 忽略大小写
         * @return 是否包含
         */
        [[nodiscard]] bool contains(const std::string &sub, bool ignoreCase = false) const;

        [[nodiscard]] inline bool contains(const char szSub[], bool ignoreCase = false) const {
            return this->contains(std::string(szSub), ignoreCase);
        }

        /**
         * 查询字符串开头是否与指定字符串相同
         * @param sub 查询的字符串
         * @param ignoreCase 忽略大小写
         * @return 是否相同
         */
        [[nodiscard]] bool startswith(const std::string &sub, bool ignoreCase = false) const;

        [[nodiscard]] inline bool startswith(const char szSub[], bool ignoreCase = false) const {
            return this->startswith(std::string(szSub), ignoreCase);
        }

        /**
         * 查询字符串结尾是否与指定字符串相同
         * @param sub 查询的字符串
         * @param ignoreCase 忽略大小写
         * @return 是否相同
         */
        [[nodiscard]] bool endswith(const std::string &sub, bool ignoreCase = false) const;

        inline bool endswith(const char szSub[], bool ignoreCase = false) const {
            return this->endswith(std::string(szSub), ignoreCase);
        }

        /**
         * 替换字符串中的部分内容
         * @param ori 要替换的内容
         * @param sub 替换成
         * @return 自身引用
         */
        inline kstring &replace(const std::string &ori, const std::string &sub) {
            size_t idx = this->mStr.find(ori);
            if (idx != static_cast<size_t>(-1)) this->mStr.replace(idx, ori.size(), sub);
            return *this;
        }

        inline kstring &replace(const std::string &ori, size_t n, const char szSub[]) {
            size_t idx = this->mStr.find(ori);
            if (idx != static_cast<size_t>(-1)) this->mStr.replace(idx, n, szSub);
            return *this;
        }

        inline kstring &replace(const char szOri[], size_t n, const char szSub[]) {
            size_t idx = this->mStr.find(szOri);
            if (idx != static_cast<size_t>(-1)) this->mStr.replace(idx, n, szSub);
            return *this;
        }

        inline kstring &replace(const char szOri[], const std::string &sub) {
            return this->replace(std::string(szOri), sub);
        }

        /**
         * 使用sprintf替换字符串的部分内容
         * @param needReplacePart 需要替换的字符串
         * @paran bufSize buf大小
         * @param format 格式
         * @param ... 参数
         * @return 自身引用
         */
        kstring &sReplace(const std::string &needReplacePart, size_t bufSize, const char *format, ...);

        /**
         * 使用sprintf格式化整个字符串
         * @param bufSize buf大小
         * @param format 格式
         * @param ... 参数
         * @return 自身引用
         */
        kstring &sprintf(size_t bufSize, const char *format, ...);

        /**
         * 从指定位置开始替换字符串的内容
         * @param pos 起始位置
         * @param sub 替换成
         * @return 自身引用
         */
        inline kstring &replace(size_t pos, const std::string &sub) {
            this->mStr.replace(pos, sub.size(), sub);
            return *this;
        }

        /**
         * 从指定位置开始替换字符串的内容
         * @param pos 起始位置
         * @param n 大小
         * @param szSub 替换成
         * @return 自身引用
         */
        inline kstring &replace(size_t pos, size_t n, const char szSub[]) {
            this->mStr.replace(pos, n, szSub);
            return *this;
        }

        /**
         * 返回一个新的对象 并将字符串内容转化为小写
         * @return kstring
         */
        [[nodiscard]] kstring toLower() const;

        /**
         * 返回一个新的对象 并将字符串内容转化为大写
         * @return kstring
         */
        [[nodiscard]] kstring toUpper() const;

        /**
         * 将自身字符串内容转化为小写 并返回自身引用
         * @return 自身引用
         */
        kstring &toLowercase();

        /**
         * 将自身字符串内容转化为大写 并返回自身引用
         * @return 自身引用
         */
        kstring &toUppercase();

        /**
         * 查询字符串出现的次数
         * @param sub string
         * @param ignoreCase 忽略大小写
         * @return 次数
         */
        [[nodiscard]] size_t queryOccurrenceTimes(const std::string &sub, bool ignoreCase = false) const;
    };

    /**
     * 往流内写入字符串
     * @param wos wostream
     * @param ks kstring
     * @return ostream
     */
    inline std::ostream &operator<<(std::ostream &os, const kstring &ks) { return os << ks.mStr; }

    /**
     * 从流内读取字符串
     * @param is istream
     * @param ks kstring
     * @return istream
     */
    inline std::istream &operator>>(std::istream &is, kstring &ks) { return is >> ks.mStr; }
}

#endif //KITSUNELIB_KSTRING_H