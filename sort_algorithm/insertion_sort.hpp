#include <vector>
namespace sort_algorithm{
    template<typename T>
    void insertion_sort(std::vector<T>& a) {
        size_t n = a.size();
        for (size_t i = 1; i < n; ++i) {
            T tmp = a[i];
            for (size_t j = i - 1; j < i && j >= 0; --j)
            {
                if (tmp < a[j])
                {
                    a[j + 1] = a[j];
                }
                else
                {
                    break;
                }
                a[j] = tmp;
            }
        }
    }
}