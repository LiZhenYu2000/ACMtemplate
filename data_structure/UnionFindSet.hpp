#include <vector>

namespace data_structure{
    template<typename T>
    class UnionFindSet
    {
    private:
        std::vector<T> se;
    public:
        UnionFindSet(size_t n):se(n + 1, -1){}
        ~UnionFindSet(){}
        T find(T& son){
            if(son < 0) return -1;
            else if(se[son] < 0)    return son;

            for(T i = se[son] ; i >= 0 ; i = se[i]){
                se[son] = i;
            }
            return se[son];
        }
        bool query(T& a, T& b){
            T x = find(a), y = find(b);
            if(x < 0 || y < 0)  return false;
            else if(x == y) return true;
            else return false;
        }
        void merge(T& a, T& b){
            T x = find(a), y = find(b);
            if(x < 0 || y < 0 ) return ;
            else if(x == y) return ;
            else{
                se[y] = x;
            }
        }
    };
} // namespace data_struct
