#include <vector>
// #include <iostream>
#include <algorithm>
// #include <utility>


namespace sort_algorithm{
    template<typename T>
    void merge(std::vector<T>& num, size_t left_begin, size_t right_begin, size_t len){
        size_t left_end = left_begin + len, 
               right_end = std::min(right_begin + len, num.size());
        
        T* left = new T[len];
        T* right = &num[right_begin];

        for (size_t m = 0; m < len; m++)
        {
            left[m] = num[m + left_begin];
        }

        for (size_t n = left_begin, left_p = 0, right_p = 0; n < left_begin + 2 * len; n++)
        {
            if (left_p < len && right_p < right_end - right_begin)
            {
                (left[left_p] <= right[right_p]) ? (num[n] = left[left_p++]) : (num[n] = right[right_p++]);
            }
            else if (left_p >= len)
            {
                num[n] = right[right_p++];
            }
            else if (right_p >= right_end - right_begin)
            {
                num[n] = left[left_p++];
            }
        }
        
        delete[] left;
    }

    template<typename T>
    void merge_sort(std::vector<T>& num){
        size_t i={0}, j;
        
        for (size_t t = 1; t < num.size(); t<<=1)
        {
            j = i + t;
            while (i < num.size())
            {
                if (j >= num.size())
                {
                    break;
                }
                merge(num, i, j, t);
                i += 2 * t;
                j = i + t;
            }
            i = 0;
        }
    }
}