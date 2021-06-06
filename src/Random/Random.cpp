//
// Created by KyuubiRan on 2021/5/31.
//

#include "Random.h"
#include <random>
#include <algorithm>
#include <ctime>

using std::vector;
using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

mt19937 &Gen() {
    static mt19937 gen(std::time(nullptr) * 233);
    return gen;
}

long kitsune::NextInt32(long from, long to) {
    uniform_int_distribution<long> distrib(from, to);
    return distrib(Gen());
}

long long int kitsune::NextInt64(long long int from, long long int to) {
    uniform_int_distribution<long long int> distrib(from, to);
    return distrib(Gen());
}

float kitsune::NextFloat(float from, float to) {
    uniform_real_distribution<float> distrib(from, to);
    return distrib(Gen());
}

double kitsune::NextDouble(double from, double to) {
    uniform_real_distribution<double> distrib(from, to);
    return distrib(Gen());
}

template<typename T>
vector<T> &kitsune::VectorRandomSort(vector<T> &v) {
    if (v.empty()) return v;
    shuffle(v.begin(), v.end(), Gen());
    return v;
}

template<typename T>
std::deque<T> &kitsune::DequeRandomSort(std::deque<T> &d) {
    if (d.empty()) return d;
    shuffle(d.begin(), d.end(), Gen());
    return d;
}
