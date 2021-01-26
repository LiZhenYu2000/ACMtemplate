#include <vector>
#include <algorithm>

namespace sort_algorithm{
    template<typename T>
    void selection_sort(std::vector<T>& a) {
    size_t n = a.size();
        for (size_t i = 0; i < n; ++i) {
            size_t ith = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (a[j] < a[ith]) {
                    ith = j;
            }
            }
            std::swap(a[i], a[ith]);
        }
    }
}