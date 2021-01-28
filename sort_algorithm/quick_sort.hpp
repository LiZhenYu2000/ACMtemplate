#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using std::vector;

namespace sort_algorithm{
    template<typename T>
    size_t chose_pivot(vector<T>&num, size_t left, size_t right){
        size_t center = (left + right) / 2;

        if(num[left] > num[center])
            std::swap(num[left], num[center]);
        if(num[left] > num[right])
            std::swap(num[left], num[right]);
        if(num[center] > num[right])
            std::swap(num[center], num[right]);

        std::swap(num[center], num[right-1]);
        return num[right-1];
    }
    inline void set_rand(){
        srand((unsigned)time(NULL));
    }
    template<typename T>
    void q_sort(vector<T>& num, long long left , long long right, size_t cutoff){
        if(cutoff + left <= right ){
            T pivot = chose_pivot(num, left, right);
            long long i = left, j = right-1;
            while(i < j){
                while(num[++i]<pivot);
                while(num[--j]>pivot);
                if( i < j )
                    std::swap(num[i], num[j]);
                else
                    break;
            }
            std::swap(num[i], num[right-1]);

            q_sort(num, left, i-1, cutoff);
            q_sort(num,i+1, right, cutoff);
        }
        else
        {
            if(num[left]>num[right])    std::swap(num[left], num[right]);
        }
        
    }
    template<typename T>
    void quick_sort(vector<T>&num, size_t n){
        set_rand();
        q_sort(num, 0, n-1, 2);
    }
}