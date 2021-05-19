//
// Created by KyuubiRan on 2021/5/15.
//

#ifndef KITSUNELIB_STRINGUTIL_H
#define KITSUNELIB_STRINGUTIL_H

#include <string>
#include <tchar.h>
#include <cwchar>
#include <cctype>

namespace kitsune {
    /**
     * 将字符串转化为小写 并返回str的引用
     * @param str 字符串
     * @return str的引用
     */
    std::string &ToLowercase(std::string &str);

    /**
     * 返回一个新的对象 并将字符串内容转化为小写
     * @param str 字符串
     * @return string
     */
    std::string ToLower(const std::string &str);

    /**
     * 将字符串转化为大写 并返回str的引用
     * @param str 字符串
     * @return str的引用
     */
    std::string &ToUppercase(std::string &str);

    /**
     * 返回一个新的对象 并将字符串内容转化为大写
     * @param str 字符串
     * @return string
     */
    std::string ToUpper(const std::string &str);

    /**
     * 查询字符串开头是否与指定字符串相同
     * @param ori 源字符串
     * @param sub 查询的字符串
     * @param ignoreCase 无视大小写
     * @return 是否相同
     */
    bool StartsWith(const std::string &ori, const std::string &sub, bool ignoreCase = false);

    /**
     * 查询字符串结尾是否与指定字符串相同
     * @param ori 源字符串
     * @param sub 查询的字符串
     * @param ignoreCase 无视大小写
     * @return 是否相同
     */
    bool EndsWith(const std::string &ori, const std::string &sub, bool ignoreCase = false);

    /**
     * 查询字符串中是否包含指定字符
     * @param ori 源字符串
     * @param sub 查询的字符串
     * @param ignoreCase 无视大小写
     * @return 是否包含
     */
    bool Contains(const std::string &ori, const std::string &sub, bool ignoreCase = false);

    /**
     * 查询指定字符串在原字符串中出现的次数
     * @param ori
     * @param sub
     * @param ignoreCase
     * @return 出现次数
     */
    size_t QueryOccurrenceTimes(const std::string &ori, const std::string &sub, bool ignoreCase = false);
}

#endif //KITSUNELIB_STRINGUTIL_H
