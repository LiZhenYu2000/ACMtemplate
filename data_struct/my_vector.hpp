#include<iostream>
#include<new>
#include<algorithm>

namespace my_vector{
    constexpr size_t DEAFAULT_CAPACITY = 20;

    template<typename T>
    class vector
    {
    private:
        size_t capacity{DEAFAULT_CAPACITY};
        size_t s{0};
        T* elem{nullptr};

    protected:
        void copyform(T *const A, size_t lo, size_t hi);
        void expand(); //扩展内存空间
        void shrink(); //减少内存空间
        size_t max(bool sorted = {false}); //寻找最大值

    public:
        inline size_t size() const { return s; }
        T& operator[](size_t rank) { return elem[rank]; }
        
        size_t insert(size_t rank, const T& e); //在指定秩处插入元素
        size_t insert(T const& e) { return insert(s, e); }

        T remove(int rank); //删除指定秩的元素
        int remove(int lo, int hi); //批量删除向量中的元素

        bool isempty() const { return !s; } //判断向量是否为空
        bool disordered() const; //检查向量是否有序
        
        int find(T const& e, size_t lo, size_t hi) const; //无序区间整体线性查找
        int find(T const& e) const{ return find(e, 0, s); } //无序区间整体线性查找
        
        int binary_search(const T& e, size_t lo, size_t hi); //二分查找
        int interpolation_search(const T& e, size_t lo, size_t hi); //fib查找
        int fibonacci_search(const T& e, size_t lo, size_t hi);
        int search(T const& e) //有序向量整体查找，返回不大于elem的元素的秩
        { return (0 >= s) ? -1 : binary_search(e, 0, s); }
        
        int deduplicate(); //删除重复元素，无序向量
        int uniquify(); //删除重复元素，有序向量

        void traverse(void (*)(T& )); //遍历向量中所有元素，并逐个处理
        
        template<typename VST>
        void traverse(VST visit); //遍历向量中所有元素，并逐个处理
        
        vector(size_t size = 0, T v = T{0}, size_t c = DEAFAULT_CAPACITY);
        vector(vector<T> const& sour) { //深拷贝，整个向量全部拷贝
            copyform(sour.elem, 0, sour.s);
        }
        vector(vector<T> const& sour, size_t lo, size_t hi) { //深拷贝，按区间拷贝向量
            copyform(sour.elem, lo, hi);
        }
        vector(vector<T> && sour):vector<T>(sour) { //深拷贝，移动构造函数，委托构造函数
        }
        ~vector();
    };
    
    template<typename T>
    size_t vector<T>::max(bool sorted){
        if (sorted)
        {
            return (elem[0] > elem[s - 1]) ? (elem[0]) : (elem[s - 1]);
        }
        size_t j {0};
        for (size_t i = 1; i < s; i++)
        {
            if (elem[j] < elem[i])
            {
                j = i;
            }
        }

        return j;
    }

    template<typename T>
    void vector<T>::copyform(T *const A, size_t lo, size_t hi){ 
        elem = new T[capacity = 2 * (hi - lo)];
        size = 0;
        while (lo < hi)
        {
            elem[size++] = A[lo++];
        }
    }

    template<typename T>
    vector<T>::vector(size_t size, T v, size_t c):elem{new T[capacity = c]}, s{size} {
        for (int i = 0; i < s; i++)
        {
            elem[i] = v;
        }
    }
    
    template<typename T>
    vector<T>::~vector()
    {
        delete[] elem;
    }
    
    template<typename T>
    void vector<T>::expand() { //缺点向量达到最大容量后可能会因为容量上溢导致数据丢失
        if (s < capacity ) //不需要扩容和超过扩容上限
        {
            return ;
        }
        capacity = std::max(capacity, DEAFAULT_CAPACITY); //最小容量
        T* oldelem = elem;
        elem = new T[capacity <<= 1];
        for (int i = 0; i < s; i++)
        {
            elem[i] = oldelem[i];
        }
        delete[] oldelem;
    }

    template<typename T>
    void vector<T>::shrink(){
        if (1.0 * s / capacity >= 0.5)
        {
            return ;
        }
        T * oldelem = elem;
        elem = new T[capacity >>= 1 + 1];
        capacity++;
        for (int i = 0; i < s; i++)
        {
            elem[i] = oldelem[i];
        }
        delete[] oldelem;
    }

    template<typename T>
    size_t vector<T>::insert(size_t rank, const T& e){ //时间复杂度O(n - r)
        expand();
        for (int i = s; i > rank; i--)
        {
            elem[i] = elem[i - 1];
        }
        elem[rank] = e; s++;
        return rank;
    }

    template<typename T>
    int vector<T>::remove (int lo, int hi){
        if (lo == hi)
        {
            return 0;
        }
        while (hi < s)
        {
            elem[lo++] = elem[hi++];
        }
        s = lo; shrink();
        return hi - lo;
    }

    template<typename T>
    T vector<T>::remove(int rank){
        T e = elem[rank];
        remove(rank, rank + 1);
        return e;
    }

    template<typename T>
    int vector<T>::find(T const& e, size_t lo, size_t hi) const{ //O(hi - lo) = O(n),input-sensitive;
        while ((lo < hi--) && (e != elem[hi])) // 逆向查找
        {
            continue;
        }
        return hi; // hi < lo 意味着查找失败;否则hi即命中元素的秩。
    }

    template<typename T>
    int vector<T>::deduplicate(){
        int oldsize = s;
        int i = 1;
        while (i < s)
        {
            (find(elem[i], 0, i) < 0) ?
            i++:
            remove(i);
        }
        return oldsize - s;
    }

    template<typename T>
    bool vector<T>::disordered() const{
        int n = 0;
        for (int i = 1; i < s; i++)
        {
            n += (elem[i] < elem[i - 1]);
        }
        return n;
    }

    template<typename T>
    int vector<T>::uniquify(){ // O(n),有序向量高效去重
        int i = 0, j = 0;
        while (++j < s)
        {
            if(elem[i] != elem[j])
                elem[++i] = elem[j];
        }
        s = ++i; shrink();
        return j - i;
    }

    template<typename T>
    void vector<T>::traverse(void (*visit)(T&)){
        for (int i = 0; i < s; i++)
        {
            visit(elem[i]);
        }
    }

    template<typename T>
    template<typename VST>
    void vector<T>::traverse(VST visit){
        for (int i = 0; i < s; i++)
        {
            visit(elem[i]);
        }
    }

    template<typename T>
    int vector<T>::binary_search(const T& e, size_t lo, size_t hi){ //二分查找O(logn), 返回不大于e的元素的下标
        while (lo < hi)
        {
            int mi = (lo + hi) >> 1;
            (e < elem[mi]) ? hi = mi : lo = mi + 1;
        }
        return --lo;
    }

    template<typename T>
    int vector<T>::fibonacci_search(const T& e, size_t lo, size_t hi){ // 斐波那契查找
        static my_vector::vector<size_t> fib(2, {0, 1});
        if (hi - lo > fib[fib.size() - 1]) {
            for (size_t i = fib.size(); fib[i] < (hi - lo); i++)
            {
                fib.insert(fib[i - 1] + fib[i - 2]);
            }
        }

        while (lo < hi)
        {
            int i = fib.interpolation_search(hi - lo, 0, fib.size());
            size_t mi = lo + fib[i] - 1;

            if (e < elem[mi])
            {
                hi = mi;
            }
            else if (elem[mi] < e)
            {
                lo = mi + 1;
            }
            else
            {
                return mi;
            }
        }
        
        return -1;
    }

    template<typename T>
    int vector<T>::interpolation_search(const T& e, size_t lo, size_t hi){
        //插值查找，通过猜测轴点极大提高收敛速度,前提是已知要查找向量中各元素随机分布的规律
        //最坏情况下退化为O(hi - lo) = O(n) == 顺序查找，平均查找成本O(loglogn)，字宽折半
        //相比二分查找通常优势不明显-除非查找宽度极大，或者比较操作成本极高
        //易受局部干扰，需引入乘法除法运算
        //可行的方法：首先通过插值查找或者折半查找缩小查找范围然后再使用二分查找
        while (lo < hi)
        {
            int mi = lo + (hi - lo) * ((1.0 * e - elem[lo]) / (elem[hi] - elem[lo]));
            (e < elem[mi]) ? hi = mi : lo = mi + 1;
        }
        return --lo;
    }
}