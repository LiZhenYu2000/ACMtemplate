#include <iostream>
#include <vector>
#include <stack>

namespace data_structure{
    constexpr size_t MAX_NUM = 2e5 + 5;
    
    template<typename T>
    class segment_tree
    {
    private:
        std::vector<T> tree;
        std::vector<T> tag_add;
        std::vector<T> tag_mult;
        unsigned long long mod;
        size_t size{0};
    protected:
        void build_tree(const std::vector<T>& terms, size_t p, size_t l, size_t r);

        size_t ls(size_t p){ return (p << 1) + 1;}
        size_t rs(size_t p){ return (p << 1) + 2;}
        
        inline void merge_sub(size_t p){
            tree[p] = (tree[ls(p)] + tree[rs(p)]) % mod;
        }
        inline void mark(size_t p, size_t l, size_t r, T delt_a, T delt_m){
            tag_mult[p] = (tag_mult[p] * delt_m) % mod;
            tag_add[p] = (tag_add[p] * delt_m + delt_a) % mod;
            tree[p] = ((tree[p] * delt_m) + delt_a * (r - l + 1)) % mod;
        }
        void down(size_t p, size_t l, size_t r){
            size_t mid = (l + r) >> 1;
            mark(ls(p), l, mid, tag_add[p], tag_mult[p]);
            mark(rs(p), mid + 1, r, tag_add[p], tag_mult[p]);
            tag_add[p] = 0;
            tag_mult[p] = 1;
        }
    public:
        segment_tree(T terms[], size_t s, unsigned long long m = {UINT64_MAX});
        segment_tree(const std::vector<T>& terms, unsigned long long m = {UINT64_MAX});
        segment_tree(std::vector<T>&& terms, unsigned long long m = {UINT64_MAX});
        segment_tree(){}

        void output();
        inline void set_mod(unsigned m){
            mod = m;
        }
        T query(size_t q_l, size_t q_r, size_t l, size_t r, size_t p);
        void update_mult(size_t nl, size_t nr, size_t l, size_t r, size_t p, T delt_m){
            if (nl <= l && r <= nr)
            {
                tag_mult[p] = (tag_mult[p] * delt_m) % mod;
                tag_add[p] = (tag_add[p] * delt_m) % mod;
                tree[p] = (tree[p] * delt_m) % mod;
                return ;
            }
            down(p, l, r);

            size_t mid = (l + r) >> 1;
            if (nl <= mid)
            {
                update_mult(nl, nr, l, mid, ls(p), delt_m);
            }
            if (nr > mid)
            {
                update_mult(nl, nr, mid + 1, r, rs(p), delt_m);
            }
            merge_sub(p);
        }

        void update_add(size_t nl, size_t nr, size_t l, size_t r, size_t p, T delt_a){
            if (nl <= l && r <= nr)
            {
                tag_add[p] = (tag_add[p] + delt_a) % mod;
                tree[p] = (tree[p] + delt_a * (r - l + 1)) % mod;
                return ;
            }
            down(p, l, r);

            size_t mid = (l + r) >> 1;
            if (nl <= mid)
            {
                update_add(nl, nr, l, mid, ls(p), delt_a);
            }
            if (nr > mid)
            {
                update_add(nl, nr, mid + 1, r, rs(p), delt_a);
            }
            merge_sub(p);
        }
        
        // ~segment_tree();
    };
    
    template<typename T>
    T segment_tree<T>::query(size_t q_l, size_t q_r, size_t l, size_t r, size_t p){
        if (q_l <= l && q_r >= r)
        {
            return tree[p];
        }
        T res = 0;
        size_t mid = (l + r) >> 1;
        down(p, l, r);
        if (q_l <= mid)
        {
            res = (res + query(q_l, q_r, l, mid, ls(p))) % mod;
        }
        if (q_r > mid)
        {
            res = (res + query(q_l, q_r, mid + 1, r, rs(p))) % mod;
        }
        return res;
    }
    template<typename T>
    void segment_tree<T>::output(){
        for (size_t i = 1, j = 1; i <= size; i++)
        {
            std::cout << tree[i - 1] << ' ';
            if (i == j)
            {
                std::cout << std::endl;
                j += (j << 1);
            }
        }
        std::cout << std::endl;
    }

    template<typename T>
    void segment_tree<T>::build_tree(const std::vector<T>& terms, size_t p, size_t l, size_t r){
        tag_add[p] = 0;
        tag_mult[p] = 1;
        
        if(l == r){
            tree[p] = terms[l];
            return ;
        }

        build_tree(terms, ls(p), l, (l + r) >> 1);
        build_tree(terms, rs(p), ((l + r) >> 1) + 1, r);

        merge_sub(p);size++;
        tree[p] %= mod;
    }

    template<typename T>
    segment_tree<T>::segment_tree(T terms[], size_t s, unsigned long long m)
    :size{s},mod{m}
    {
        if (size != 0)
        {
            tree.resize(data_struct::MAX_NUM, T{});
            tag_add.resize(data_struct::MAX_NUM, T{});
            tag_mult.resize(data_struct::MAX_NUM, T{});
            build_tree(std::vector<T>(terms, terms + s), 0, 0, size - 1);
        }
    }
    
    template<typename T>
    segment_tree<T>::segment_tree(std::vector<T>&& terms, unsigned long long m)
    :size{terms.size()},mod{m}
    {
        if (size != 0)
        {
            tree.resize(data_struct::MAX_NUM, T{});
            tag_add.resize(data_struct::MAX_NUM, T{});
            tag_mult.resize(data_struct::MAX_NUM, T{});
            build_tree(terms, 0, 0, size - 1);
        }
    }

    template<typename T>
    segment_tree<T>::segment_tree(const std::vector<T>& terms, unsigned long long m)
    :size{terms.size()},mod{m}
    {
        if (size != 0)
        {
            tree.resize(data_struct::MAX_NUM, T{});
            tag_add.resize(data_struct::MAX_NUM, T{});
            tag_mult.resize(data_struct::MAX_NUM, T{});
            build_tree(terms, 0, 0, size - 1);
        }
    }
}