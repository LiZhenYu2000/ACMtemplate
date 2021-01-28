#include<vector>
#include<iostream>

namespace data_struct{
    
    template<typename T>
    class BI_tree{
        std::vector<T> suf;
        size_t a_size{0};
    protected:
        size_t lowbit(long long x){
            return static_cast<size_t>(x&(-x));
        }
    public:
        T query(size_t x){
            T res = 0;
            while (x)
            {
                res += suf[x];
                x -= lowbit(x);
            }
            return res;
        }
        void add(size_t x, T v){
            while (x <= a_size)
            {
                suf[x] += v;
                x += lowbit(x);
            }
        }
        void output(){
            for (size_t i = 1; i <= a_size; i++)
            {
                std::cout << suf[i] << std::endl;
            }
            
        }
        BI_tree(const std::vector<T>& num)
        :a_size{num.size()},suf(1e8){
            for(size_t i = 1;i < num.size();i++){
                add(i, num[i]);
            }
        }
        BI_tree():suf(1e8){}

        BI_tree(std::vector<T>&& num)
        :BI_tree(num){}

        BI_tree(T* num, size_t n)
        :BI_tree(std::vector<T>(num, num + n + 1)){}

    };
}