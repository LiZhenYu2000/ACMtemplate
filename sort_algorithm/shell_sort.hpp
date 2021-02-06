#include <vector>
using std::vector;

namespace sort_algorithm{
    template<typename T>
    void shell_sort(vector<T>&num, size_t n){
        size_t i , j , increment;
        T tmp;
        for (increment = n/2; increment > 0; increment/=2) {
            for(i = increment; i < n; i++) {
                tmp = num[i];
                for(j = i; j>=increment; j-=increment) {
                    if(tmp < num[j - increment])
                        num[j] = num[j - increment];
                    else
                        break;
                }
                num[j] = tmp;
            }
        }
        
    }
}