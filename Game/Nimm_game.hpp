#include <iostream>

namespace game{
    bool Nimm(int n){
        // 有n堆东西， 两人轮流取， 每次取堆中不少于一个， 最后取完者胜
        int arr[10000];
        int res = 0;
        for (size_t i = 1; i <= n; i++)
        {
            res ^= arr[i];
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