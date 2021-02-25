#include <vector>
#include <algorithm>

namespace data_structure{
    using std::vector;
    using std::swap;
    using std::greater;
    template<typename T>
    class BinaryHeap
    {
    private:
        vector<T> heap;
        size_t root;
        size_t size;
        size_t ls(size_t root){
            return root << 1;
        }
        size_t rs(size_t root){
            return (root << 1) + 1;
        }
        size_t fa(size_t son){
            return son >> 1;
        }
        void percolate_up(size_t pos){
            size_t fpos = fa(pos);
            T tmp = heap[pos];
            while(fpos){
                if(heap[fpos] <= tmp){
                    break;
                }
                heap[pos] = heap[fpos];
                pos = fpos;fpos = fa(pos);
            }
            heap[pos] = tmp;
        }
        void percolate_down(size_t pos){
            size_t big, l = ls(pos), r = rs(pos);
            T tmp = heap[pos];
            while(l <= size || r <= size){
                if(l <= size && r <= size)
                    (heap[l] <= heap[r]) ? big = l : big = r;
                else if(l <= size)
                    big = l;
                else if(r <= size)
                    big = r;

                if(tmp <= heap[big]){
                    break;
                }
                
                heap[pos] = heap[big];
                pos = big;
                l = ls(pos); r = rs(pos);
            }
            heap[pos] = tmp;
        }
        void heapify(){
            for(size_t i = size / 2; i >= root ; i--){
                percolate_down(i);
            }
        }
        void copy_from(vector<T>& num, size_t n){
            heap.resize(n + 1);size = n;
            for (size_t i = 0; i < n; i++)
            {
                heap[i + 1] = num[i];
            }
        }
    public:
        void build_heap(vector<T>& num, size_t n){
            copy_from(num, n);
            heapify();
        }
        T top(void){
            return heap[root];
        }
        void pop(void){
            if(size == 0)
                return ;
            swap(heap[root], heap[size--]);
            percolate_down(root);
        }
        void insert(T& num){
            if(size < heap.size() - 1){
                heap[++size] = num;
                percolate_up(size);
            }
            else{
                heap.emplace_back(T{num});++size;
                percolate_up(size);
            }
        }
        BinaryHeap(vector<T>& num, size_t n ):root{1}{
            build_heap(num, n);
        }
        BinaryHeap(vector<T>&& num, size_t n ):BinaryHeap(num, n){}
        BinaryHeap(const T* num, size_t n ):BinaryHeap(vector<T>(num, num + n ), n){}
        BinaryHeap():size{0}, root{1}, heap(1){}
        ~BinaryHeap(){}
    };
}