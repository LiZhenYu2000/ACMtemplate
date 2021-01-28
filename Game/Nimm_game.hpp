#include <iostream>

namespace game{
    bool Nimm(size_t n){
        // 有n堆东西， 两人轮流取， 每次取堆中不少于一个， 最后取完者胜
        unsigned long long arr;
        unsigned long long res = 0;
        for (size_t i = 1; i <= n; i++)
        {
            cin >> arr;
            res ^= arr;
        }
        if (res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}