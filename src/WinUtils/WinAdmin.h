//
// Created by KyuubiRan on 2021/6/2.
//

#ifndef KITSUNELIB_WINADMIN_H
#define KITSUNELIB_WINADMIN_H

#ifdef WIN32

namespace kitsune {
    /**
     * 查询当前进程是否含有管理员权限
     * @return 是否有权限
     */
    [[nodiscard]] bool IsCurrentProcessHasAdminPrivileges();
}

#else
#error "OS NOT SUPPORTED!"
#endif //WIN32

#endif //KITSUNELIB_WINADMIN_H
