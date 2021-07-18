//
// Created by KyuubiRan on 2021/5/15.
//

#ifndef KITSUNETOOLS_WINPROCESS_H
#define KITSUNETOOLS_WINPROCESS_H

#ifdef WIN32

#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include <iostream>

namespace kitsune {
    typedef long int32;
    typedef unsigned long uint32, uintptr32;
    typedef long long int64;
    typedef unsigned long long uint64, uintptr64, size;

    constexpr size INVALID_SIZE = static_cast<size>(-1);

    /**
     * 通过进程名称获取Pid
     * @param procName 进程名称
     * @return 获取成功时返回进程pid 获取失败时返回0
     */
    DWORD GetProcessPidByName(const std::string &procName);

    /**
     *
     * @param procName 进程名称
     * @param pid 进程id
     * @return 是否成功
     */
    bool GetProcessPidByName(const std::string &procName, DWORD &pid);

    /**
     * 获取模块基址
     * @param hProc 进程句柄
     * @param moduleName 模块名
     * @return 模块基址
     */
    uintptr64 GetModuleBaseAddress(HANDLE hProc, const std::string &moduleName);

    /**
     * 获取模块基址
     * @param hProc 进程句柄
     * @param moduleName 模块名
     * @param address 传入的地址
     * @return 是否成功
     */
    bool GetModuleBaseAddress(HANDLE hProc, const std::string &moduleName, uintptr64 &address);

    /**
     * 获取模块
     * @param pid 进程id
     * @param moduleName 模块名
     * @return 模块
     */
    HMODULE GetProcessModuleHandle(DWORD pid, const char moduleName[]);

    /**
     * 计算偏移量
     * @param hProc 进程句柄
     * @param baseAddress 基址
     * @param vOffsets 偏移量(向量)
     * @return 计算完毕后的地址
     */
    uintptr64 CalculateAddress(HANDLE hProc, uintptr64 baseAddress, const std::vector<uintptr64> &vOffsets);

    /**
     * 给当前进程提权 需要管理员权限
     * @return 是否成功
     */
    bool UpPrivilege();

    /**
     * 通过Pid杀死进程
     * @param pid 进程id
     * @param exitCode 退出id
     * @return 是否成功
     */
    bool KillProcess(DWORD pid, int exitCode = 0);

    /**
     * 通过进程名杀死进程
     * @param pid 进程id
     * @param exitCode 退出id
     * @return 是否成功
     */
    bool KillProcessByName(const std::string &procName, int exitCode = 0);

    /**
     * 枚举PROCESSENTRY32信息
     * @param vPe32 PROCESSENTRY32向量
     * @return 是否成功
     */
    bool EnumProcessEntry32(DWORD pid, std::vector<PROCESSENTRY32> &vPe32);

    /**
     * 搜索BYTES的位置
     * @param origin 源BYTES
     * @param search 要搜索的BYTES
     * @return 成功时返回index 失败时返回npos
     */
    size ScanBytes(const std::vector<BYTE> &origin, const std::vector<BYTE> &search);

    /**
     * 搜索BYTES的位置
     * @param origin 源BYTES
     * @param nOriSize 源BYTES大小
     * @param search 要搜索的BYTES
     * @param nSchSize 要搜索的BYTES大小
     * @return 成功时返回index 失败时返回npos
     */
    inline size ScanBytes(const BYTE origin[], size nOriSize, const BYTE search[], size nSchSize) {
        return ScanBytes(std::vector<BYTE>(origin, origin + nOriSize), std::vector<BYTE>(search, search + nSchSize));
    }

//    std::vector<uintptr64> &
//    AobScan(HANDLE hProc, uintptr64 startAddress, const BYTE bytes[], size nSize, std::vector<uintptr64> &result,
//            size nScanSize = 4096);
}
#else
#error "OS NOT SUPPORTED!"
#endif //WIN32

#endif //KITSUNETOOLS_WINPROCESS_H
