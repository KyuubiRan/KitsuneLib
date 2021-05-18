//
// Created by KyuubiRan on 2021/5/15.
//

#ifndef KITSUNETOOLS_WINPROCESS_H
#define KITSUNETOOLS_WINPROCESS_H

#ifdef _WIN32

#include "TypeDef/TypeDef.h"
#include <windows.h>
#include <vector>
#include <iostream>

namespace kitsune {

    /**
     * 通过进程名称获取Pid
     * @param procName 进程名称
     * @return 获取成功时返回进程pid 获取失败时返回0
     */
    DWORD GetProcessPidByName(const std::string &procName);

    /**
     *
     * @param procName 进程名称
     * @param pid 传入的pid
     * @return 是否成功
     */
    bool GetProcessPidByName(const std::string &procName, DWORD &pid);

    /**
     * 获取模块基址
     * @param hProc 进程句柄
     * @param moduleName 模块名
     * @return 模块基址
     */
    kitsune::uintptr64 GetModuleBaseAddress(HANDLE hProc, const std::string &moduleName);

    /**
     * 获取模块基址
     * @param hProc 进程句柄
     * @param moduleName 模块名
     * @param address 传入的地址
     * @return 是否成功
     */
    bool GetModuleBaseAddress(HANDLE hProc, const std::string &moduleName, kitsune::uintptr64 &address);

    /**
     * 计算偏移量
     * @param hProc 进程句柄
     * @param baseAddress 基址
     * @param vOffsets 偏移量(向量)
     * @return 计算完毕后的地址
     */
    kitsune::uintptr64
    CalculateAddress(HANDLE hProc, kitsune::uintptr64 baseAddress, const std::vector<kitsune::uintptr64> &vOffsets);

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
    bool KillProcessByName(const std::string& procName, int exitCode = 0);
}
#else
#error "OS NOT SUPPORTED!"
#endif //_WIN32

#endif //KITSUNETOOLS_WINPROCESS_H
