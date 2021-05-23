//
// Created by KyuubiRan on 2021/5/19.
//

#ifndef KITSUNELIB_DATEFORMAT_H
#define KITSUNELIB_DATEFORMAT_H

#include <string>
#include <chrono>

namespace kitsune {
    /**
     * 格式                 eg: 2021/05/20 21:15:12 (yyyy/MM/dd HH:mm:ss)
     * y - 年                    yyyy    2021 | yy 21
     * M - 月                    MM      05
     * d - 日                    dd      20
     * H - 24小时制 小时          HH      21
     * h - 12小时制 小时          hh      09
     * m - 分                    mm      15
     * s - 秒                    ss      12
     *
     * 注意:当月、日、时、分、秒的格式为一个字母(如 yyyy/M/d H:m:s)时
     * 如果为一位数 则显示一位数 如果为两位数 则显示两位数
     * eg: 2021/5/21 16:8:31
     */

    /**
     * 获取当前系统时间（毫秒）
     * @return 毫秒
     */
    [[nodiscard]] inline std::chrono::milliseconds GetCurrentMilliseconds() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch());
    }

    /**
     * 获取当前系统时间（秒）
     * @return 秒
     */
    [[nodiscard]] inline std::chrono::seconds GetCurrentSeconds() {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
    }

    /**
     * 获取包含现在时间的现在的tm
     * @return tm时间信息
     */
    [[nodiscard]] inline std::tm GetNowTm() {
        time_t now = time(nullptr);
        return *localtime(&now);
    }

    /**
     * 将秒数转化为tm
     * @param sec 秒
     * @return tm时间信息
     */
    [[nodiscard]] inline std::tm SecondsToTm(time_t sec) {
        return *localtime(&sec);
    }

    /**
     * 将秒数转化为tm
     * @param sec 秒
     * @return tm时间信息
     */
    [[nodiscard]] inline std::tm SecondsToTm(const std::chrono::seconds &sec) {
        return SecondsToTm(sec.count());
    }

    /**
     * 获取格式化后的时间
     * @param fmt 格式 如yyyy-MM-dd HH:mm:ss
     * @param timeInfo 时间信息
     * @return 格式化后的字符串
     */
    [[nodiscard]] std::string GetFormatDate(const std::string &fmt, const std::tm &timeInfo);

    /**
     * 获取格式化后的时间
     * @param fmt 格式 如yyyy-MM-dd HH:mm:ss
     * @param sec 秒
     * @return 格式化后的字符串
     */
    [[nodiscard]] inline std::string GetFormatDate(const std::string &fmt, const std::chrono::seconds &sec) {
        return GetFormatDate(fmt, SecondsToTm(sec));
    }

    /**
     * 获取格式化后的时间
     * @param fmt 格式 如yyyy-MM-dd HH:mm:ss
     * @param sec 秒
     * @return 格式化后的字符串
     */
    [[nodiscard]] inline std::string GetFormatDate(const std::string &fmt, const time_t sec) {
        return GetFormatDate(fmt, SecondsToTm(sec));
    }

    /**
     * 获取简单的格式化时间
     * @param sec
     * @return yyyy-MM-dd HH:mm:ss格式的时间
     */
    [[nodiscard]] inline std::string GetSimpleFormatDate(const time_t sec) {
        return GetFormatDate("yyyy-MM-dd HH:mm:ss", SecondsToTm(sec));
    }

    /**
     * 获取简单的格式化时间
     * @param timeInfo 时间信息
     * @return yyyy-MM-dd HH:mm:ss格式的时间
     */
    [[nodiscard]] inline std::string GetSimpleFormatDate(const std::tm timeInfo) {
        return GetFormatDate("yyyy-MM-dd HH:mm:ss", timeInfo);
    }
}

#endif //KITSUNELIB_DATEFORMAT_H
