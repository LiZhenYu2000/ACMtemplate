#include <iostream>

namespace game{
    bool Nimm(size_t n){
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