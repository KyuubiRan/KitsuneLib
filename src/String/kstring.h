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

        inline kstring(const char sz[]) : mStr(sz) {}; // NOLINT(google-explicit-constructor)

        inline explicit kstring(std::string str) : mStr(std::move(str)) {};

        inline explicit operator std::string() const { return mStr; }

        /**
       * 比较字符串是否相等
       * @param str string
       * @return 是否相等
       */
        inline bool equals(const std::string &str) { return this->mStr == str; }

        inline bool equals(const char sz[]) { return this->mStr == sz; }

        inline bool operator==(const std::string &str) { return this->equals(str); }

        inline bool operator==(const char sz[]) { return this->equals(sz); }

        /**
         * 拼接字符串
         * @param str string
         * @return 自身引用
         */
        inline kstring &append(const std::string &str) {
            mStr.append(str);
            return *this;
        }

        inline kstring &append(const char sz[]) {
            mStr.append(sz);
            return *this;
        }

        /**
         * 查找字符串index
         * @param str string
         * @return index
         */
        inline size_t find(const std::string &str) { return mStr.find(str); }

        inline size_t find(const kstring &kStr) { return mStr.find(kStr.mStr); }

        inline size_t find(const char sz[]) { return mStr.find(sz); }

        inline size_t find(const char ch) { return mStr.find(ch); }

        /**
         * @return 字符串长度
         */
        inline size_t size() { return mStr.size(); }

        inline size_t length() { return mStr.length(); }

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
        inline kstring substring(size_t pos = 0, size_t end = static_cast<size_t>(-1)) {
            return kstring(mStr.substr(pos, end));
        }

        /**
         * 查询字符串中是否包含指定字符
         * @param sub 查询的字符串
         * @param ignoreCase 无视大小写
         * @return 是否包含
         */
        bool contains(const std::string &sub, bool ignoreCase = false);

        inline bool contains(const char szSub[], bool ignoreCase = false) {
            return this->contains(std::string(szSub), ignoreCase);
        }

        /**
         * 查询字符串开头是否与指定字符串相同
         * @param sub 查询的字符串
         * @param ignoreCase 无视大小写
         * @return 是否相同
         */
        bool startswith(const std::string &sub, bool ignoreCase = false);

        inline bool startswith(const char szSub[], bool ignoreCase = false) {
            return this->startswith(std::string(szSub), ignoreCase);
        }

        /**
         * 查询字符串结尾是否与指定字符串相同
         * @param sub 查询的字符串
         * @param ignoreCase 无视大小写
         * @return 是否相同
         */
        bool endswith(const std::string &sub, bool ignoreCase = false);

        inline bool endswith(const char szSub[], bool ignoreCase = false) {
            return this->endswith(std::string(szSub), ignoreCase);
        }

        /**
         * 替换字符串中的部分内容
         * @param ori 要替换的内容
         * @param sub 替换成
         * @return 自身引用
         */
        inline kstring &replace(const std::string &ori, const std::string &sub) {
            this->mStr.replace(this->mStr.find(ori), ori.size(), sub);
            return *this;
        }

        inline kstring &replace(const std::string &ori, size_t n, const char szSub[]) {
            this->mStr.replace(this->mStr.find(ori), n, szSub);
            return *this;
        }

        inline kstring &replace(const char szOri[], size_t n, const char szSub[]) {
            this->mStr.replace(this->mStr.find(szOri), n, szSub);
            return *this;
        }

        inline kstring &replace(const char szOri[], const std::string &sub) {
            this->mStr.replace(this->mStr.find(szOri), sub.size(), sub);
            return *this;
        }

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

        inline kstring &replace(size_t pos, size_t n, const char szSub[]) {
            this->mStr.replace(pos, n, szSub);
            return *this;
        }

        /**
         * 返回一个新的对象 并将字符串内容转化为小写
         * @return kstring
         */
        kstring toLower();

        /**
         * 返回一个新的对象 并将字符串内容转化为大写
         * @return kstring
         */
        kstring toUpper();

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
    };

    /**
     * 往流内写入字符串
     * @param os ostream
     * @param ks kstring
     * @return ostream
     */
    inline std::ostream &operator<<(std::ostream &os, const kstring &ks) { return os << ks.mStr; }

    /**
     * 从流内读取字符串
     * @param is istream
     * @return istream
     */
    inline std::istream &operator>>(std::istream &is, kstring &ks) { return is >> ks.mStr; }
}

#endif //KITSUNELIB_KSTRING_H