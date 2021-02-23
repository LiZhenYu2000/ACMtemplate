#include <iostream>

namespace game{
    bool Fibo(int n){
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