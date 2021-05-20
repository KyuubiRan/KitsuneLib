//
// Created by KyuubiRan on 2021/5/19.
//

#ifndef KITSUNELIB_DATEFORMAT_H
#define KITSUNELIB_DATEFORMAT_H

#include <string>
#include <chrono>

namespace kitsune {
    /**
     * y - 年
     * M - 月
     * d - 日
     * H - 24小时制 小时
     * h - 12小时制 小时
     * m - 分
     * s - 秒
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
     * @param timeinfo tm时间信息
     * @return 格式化后的字符串
     */
    [[nodiscard]] std::string GetFormatDate(const std::string &fmt, const std::tm &timeinfo);

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
}

#endif //KITSUNELIB_DATEFORMAT_H
