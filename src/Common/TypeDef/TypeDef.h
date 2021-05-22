//
// Created by KyuubiRan on 2021/5/15.
//

#ifndef KITSUNETOOLS_TYPEDEF_H
#define KITSUNETOOLS_TYPEDEF_H

namespace kitsune {
    typedef long int32;
    typedef unsigned long uint32, uintptr32;
    typedef long long int64;
    typedef unsigned long long uint64, uintptr64, size;

    constexpr size INVALID_SIZE = static_cast<size>(-1);
}

#endif //KITSUNETOOLS_TYPEDEF_H
