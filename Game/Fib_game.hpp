#include <iostream>

namespace game{
    bool Fibo(int n){
        // 一堆物品里有n个，两人轮流取， 先取者一次可取任意多个，但是不能取完
        // 以后每次取得石子不能超过上次的两倍，先取完者胜利
        int f[10000];
        f[0] = f[1] = 1;
        for (size_t i = 2; f[i - 1] < n; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
            if (f[i] == n)
            {
                return true;
            }
        }
        return false;
    }
}