#include <vector>

namespace game{
    template<typename T>
    bool Nimm(const std::vector<T>& num, size_t left, size_t right){
        T arr;
        T res = 0;
        for (size_t i = left; i <= right; i++)
        {
            arr += num[i];
            res ^= arr;
        }
        return (res) ? true : false;
    }
}