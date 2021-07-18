//
// Created by KyuubiRan on 2021/5/15.
//

#include "WinProcess.h"
#include <psapi.h>
#include <tchar.h>
#include <memory>

using namespace kitsune;
using std::string;
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;

DWORD kitsune::GetProcessPidByName(const string &procName) {
    TCHAR tszProcess[64] = {0};
    lstrcpy(tszProcess, _T(procName.c_str()));

    STARTUPINFO st;
    PROCESS_INFORMATION pi;
    PROCESSENTRY32 ps;
    HANDLE hSnapshot;

    memset(&st, 0, sizeof st);
    st.cb = sizeof st;
    memset(&ps, 0, sizeof ps);
    ps.dwSize = sizeof ps;
    memset(&pi, 0, sizeof pi);

    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot) return 0;
    if (!Process32First(hSnapshot, &ps)) return 0;
    do {
        if (lstrcmp(ps.szExeFile, tszProcess) == 0) {
            CloseHandle(hSnapshot);
            return ps.th32ProcessID;
        }
    } while (Process32Next(hSnapshot, &ps));
    CloseHandle(hSnapshot);
    return 0;
}

bool kitsune::GetProcessPidByName(const std::string &procName, DWORD &pid) {
    DWORD buf = GetProcessPidByName(procName);
    if (!buf) {
        return false;
    } else {
        pid = buf;
        return true;
    }
}

uintptr64 kitsune::GetModuleBaseAddress(HANDLE hProc, const string &moduleName) {
    HMODULE hModule[1024];
    DWORD cbNeeded;
    char szModName[MAX_PATH] = {0};
    if (EnumProcessModules(hProc, hModule, sizeof(hModule), &cbNeeded)) {
        for (int i = 0; i < cbNeeded / sizeof(HMODULE); ++i) {
            if (::GetModuleBaseNameA(hProc, hModule[i], szModName, sizeof(szModName))) {
                if (string(szModName) == moduleName) return reinterpret_cast<uintptr64>(hModule[i]);
            }
        }
    }
    return 0;
}

bool kitsune::GetModuleBaseAddress(HANDLE hProc, const string &moduleName, uintptr64 &address) {
    uintptr64 buf = GetModuleBaseAddress(hProc, moduleName);
    if (!buf) {
        return false;
    } else {
        address = buf;
        return true;
    }
}

HMODULE kitsune::GetProcessModuleHandle(DWORD pid, const char moduleName[]) {
    MODULEENTRY32 moduleEntry;
    HANDLE handle;
    handle = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
    if (!handle) {
        CloseHandle(handle);
        return nullptr;
    }
    ZeroMemory(&moduleEntry, sizeof(MODULEENTRY32));
    moduleEntry.dwSize = sizeof(MODULEENTRY32);
    if (!Module32First(handle, &moduleEntry)) {
        CloseHandle(handle);
        return nullptr;
    }
    do {
        if (_tcscmp(moduleEntry.szModule, moduleName) == 0) {
            CloseHandle(handle);
            return moduleEntry.hModule;
        }
    } while (Module32Next(handle, &moduleEntry));
    CloseHandle(handle);
    return nullptr;
}


kitsune::uintptr64 kitsune::CalculateAddress(HANDLE hProc, uintptr64 baseAddress, const vector<uintptr64> &vOffsets) {
    uintptr64 result = baseAddress;
    for (int i = 0; i < vOffsets.size(); ++i) {
        result += vOffsets[i];
        if (i < vOffsets.size() - 1) {
            uintptr64 buf;
            if (ReadProcessMemory(hProc, reinterpret_cast<LPCVOID>(result), &buf, sizeof(buf), nullptr)) {
                result = buf;
            } else {
                return 0;
            }
        }
    }
    return result;
}

bool kitsune::UpPrivilege() {
    HANDLE hToken;
    TOKEN_PRIVILEGES tps;
    LUID luid;
    bool result;
    result = OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
    if (!result) {
        return false;
    }
    result = LookupPrivilegeValue(nullptr, SE_DEBUG_NAME, &luid);
    if (!result) {
        CloseHandle(hToken);
        return false;
    }
    tps.Privileges[0].Luid = luid;
    tps.PrivilegeCount = 1;
    tps.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    result = AdjustTokenPrivileges(hToken, FALSE, &tps, sizeof tps, nullptr, nullptr);
    CloseHandle(hToken);
    return result;
}

bool kitsune::KillProcess(DWORD pid, int exitCode) {
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (INVALID_HANDLE_VALUE == hProc) return false;
    TerminateProcess(hProc, exitCode);
    return true;
}

bool kitsune::KillProcessByName(const std::string &procName, int exitCode) {
    DWORD pid = GetProcessPidByName(procName);
    if (!pid) return false;
    return KillProcess(pid, exitCode);
}

bool kitsune::EnumProcessEntry32(DWORD pid, vector<PROCESSENTRY32> &vPe32) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, pid);
    if (INVALID_HANDLE_VALUE == hSnapshot) return false;
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(pe);
    if (!Process32First(hSnapshot, &pe)) {
        CloseHandle(hSnapshot);
        return false;
    }
    do {
        vPe32.push_back(pe);
    } while (Process32Next(hSnapshot, &pe));
    CloseHandle(hSnapshot);
    return true;
}

size kitsune::ScanBytes(const vector<BYTE> &origin, const vector<BYTE> &search) {
    if (search.size() > origin.size()) return string::npos;
    string s1, s2;
    char buf[3]{};
    for (auto o:origin) {
        sprintf(buf, "%02x", o);
        s1.append(buf);
    }
    for (auto s:search) {
        sprintf(buf, "%02x", s);
        s2.append(buf);
    }
    size pos = s1.find(s2);
    return pos == string::npos ? string::npos : pos / 2;
}

//std::vector<uintptr64> &
//kitsune::AobScan(HANDLE hProc, uintptr64 startAddress, const BYTE bytes[], size nSize, vector<uintptr64> &result,
//                 size nScanSize) {
//    unique_ptr<BYTE[]> buf(new BYTE[nScanSize]{});
//    size read;
//    while (ReadProcessMemory(hProc, (LPCVOID) startAddress, buf.get(), nScanSize, &read)) {
//        size pos = 0;
//        while (true) {
//            pos = ScanBytes(buf.get() + pos, read - pos, bytes, nSize);
//            if (pos == string::npos) break;
//            result.push_back(startAddress + pos);
//        }
//        startAddress += nScanSize;
//    }
//    return result;
//}




