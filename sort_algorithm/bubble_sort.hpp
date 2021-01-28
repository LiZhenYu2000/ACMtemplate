#include <vector>
#include <iostream>

namespace sort_algorithm{
    template<typename T>
    void bubble_sort(std::vector<T>& num, size_t n){
        for (bool sorted = false; sorted = !sorted; n--)
        {
            for (size_t i = 1; i < n; i++)
            {
                if (num[i - 1] > num[i])
                {
                    std::swap(num[i - 1], num[i]);
                    sorted = false;
                }
            }
        }
    }
}