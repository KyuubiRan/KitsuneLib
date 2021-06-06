//
// Created by KyuubiRan on 2021/5/31.
//

#ifndef KITSUNELIB_RANDOM_H
#define KITSUNELIB_RANDOM_H

#include <vector>
#include <deque>

namespace kitsune {
    /**
     * @param from 最小值
     * @param to 最大值
     * @return [from,to]之间的随机数
     */
    long NextInt32(long from, long to);

    /**
     * @return [0,1]之间的随机数
     */
    inline long NextInt32() { return NextInt32(0, 1); }

    /**
     * @param to 最大值
     * @return [0,to]之间的随机数
     */
    inline long NextInt32(long to) { return NextInt32(0, to); }

    /**
     * @param from 最小值
     * @param to 最大值
     * @return [from,to]之间的随机数
     */
    long long int NextInt64(long long int from, long long int to);

    /**
     * @param from 最小值
     * @param to 最大值
     * @return [0,to]之间的随机数
     */
    inline long long int NextInt64(long long int to) { return NextInt64(0, to); }

    /**
     * @param from 最小值
     * @param until 最大值
     * @return [0,1]之间的随机数
     */
    inline long long int NextInt64() { return NextInt64(0, 1); }

    /**
     * @param from 最小值
     * @param to 最大值
     * @return [from,to]之间的随机浮点数
     */
    float NextFloat(float from, float to);

    /**
     * @param from 最小值
     * @param to 最大值
    * @return [0.0f,to]之间的随机浮点数
    */
    inline float NextFloat(float to) { return NextFloat(0.0f, to); }

    /**
     * @param from 最小值
     * @param to 最大值
     * @return [0.0f,1.0f]之间的随机浮点数
     */
    inline float NextFloat() { return NextFloat(1.0f); }

    /**
     * @param from 最小值
     * @param to 最大值
     * @return [from,to]之间的随机双精度浮点数
     */
    double NextDouble(double from, double to);

    /**
     * @param from 最小值
     * @param to 最大值
     * @return [0.0,to]之间的随机双精度浮点数
     */
    inline double NextDouble(double to) { return NextDouble(0.0, to); }

    /**
     * @param from 最小值
     * @param to 最大值
     * @return [0.0,1.0]之间的随机双精度浮点数
     */
    inline double NextDouble() { return NextDouble(1.0); }

    /**
     * 随机排列vector中的元素
     * @tparam T 类型
     * @param v vector
     * @return vector自身
     */
    template<typename T>
    std::vector<T> &VectorRandomSort(std::vector<T> &v);

    /**
     * 随机排列deque中的元素
     * @tparam T 类型
     * @param d deque
     * @return deque自身
     */
    template<typename T>
    std::deque<T> &DequeRandomSort(std::deque<T> &d);
}

#endif //KITSUNELIB_RANDOM_H
