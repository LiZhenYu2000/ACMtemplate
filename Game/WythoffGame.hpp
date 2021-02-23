#include <cmath>
#include <algorithm>

namespace game{
    template<typename T>
    bool Wythoff(T a, T b){
        auto r = (std::sqrt(5) + 1) / 2;
        T d = std::abs(a - b) * r;
        if (d != std::min(a, b))
        {
            return true;
        }
        return false;
    }
}