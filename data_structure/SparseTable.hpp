#include <vector>
#include <cmath>
#include <algorithm>

namespace data_structure{
    using std::vector;
    template<typename T>
    class ST_table{
        size_t p;
        vector<vector<T>> range;
    public:
        void build(vector<T>& num, size_t n){
            p = std::log2(n);
            range.resize(n,vector<T>(p+1));
            for (size_t i = 0; i < n; i++)
            {
                range[i][0] = num[i];
            }
            for (size_t i = 1; i <= p; i++)
            {
                for (size_t j = 0; j+(1 << i)-1 < n; j++)
                {
                    range[j][i] = std::max(range[j][i-1], range[j+(1<<(i-1))][i-1]);
                }
            }
        }
        ST_table(vector<T>& num, size_t n){
            build(num, n);
        }
        ST_table(vector<T>&& num, size_t n):ST_table(num, n){}
        ST_table(T* num, size_t n):ST_table(vector<T>(num, num+n), n){}
        ~ST_table(){}
        T query(size_t l ,size_t r){
            size_t k = std::log2(r - l + 1);
            return std::max(range[l][k], range[r-(1<<k)+1][k]);
        }
    };
}