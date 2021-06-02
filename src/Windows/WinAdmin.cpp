//
// Created by KyuubiRan on 2021/6/2.
//

#include "WinAdmin.h"
#include <windows.h>

bool kitsune::IsCurrentProcessHasAdminPrivileges() {
    HANDLE hToken;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) return false;
    TOKEN_ELEVATION tokenEle;
    DWORD dwRetLen;
    if (GetTokenInformation(hToken, TokenElevation, &tokenEle, sizeof(tokenEle), &dwRetLen)) {
        if (dwRetLen != sizeof(tokenEle)) return false;
    }
    CloseHandle(hToken);
    return tokenEle.TokenIsElevated;
}