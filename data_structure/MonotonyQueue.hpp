#include<deque>
#include<vector>
#include<algorithm>
#include<utility>

namespace data_structure{
    using std::vector;
    using std::deque;
    using std::pair;
    using std::make_pair;
    template<typename T>
    class MonotonyQueue
    {
    private:
        size_t window{1};
        vector<T> mx;
        vector<T> mn;
        deque<pair<T, size_t>> ic, dc;

        void test_front(size_t i){
            while(!ic.empty() && ic.front().second < i ){
                ic.pop_front();
            }
            mn.emplace_back(ic.front().first);
            while(!dc.empty() && dc.front().second < i ){
                dc.pop_front();
            }
            mx.emplace_back(dc.front().first);
        }

        void insert_back(const T& num, size_t i){
            while(!ic.empty() && ic.back().first > num){
                ic.pop_back();
            }
            ic.emplace_back(make_pair(num,i));
            while(!dc.empty() && dc.back().first < num){
                dc.pop_back();
            }
            dc.emplace_back(make_pair(num,i));
        }
    public:
        void build(vector<T>& num, size_t n){
            size_t win = std::min(n, window);
            if(win == 0)
                return ;
            else{
                for(size_t i = 0 ; i < win ; i ++){
                    insert_back(num[i], i);
                }
                test_front(0);
                for(size_t i = win ; i < n ; i ++ ){
                    insert_back(num[i], i);
                    test_front(i - win + 1);
                }
                test_front(n - win + 1);
                ic.clear(), dc.clear();
            }
        }
        void build(const T* num, size_t n){
            build(vector<T>(num, num + n), n);
        }
        void build(vector<T>&& num, size_t n){
            build(num, n);
        }
        size_t step(){
            return mn.size() - 1;
        }
        T stepMin(size_t n){
            if(n < 1 || n > mn.size() - 1)
                return T{0};
            return mn[n - 1];
        }
        T stepMax(size_t n){
            if(n < 1 || n > mx.size() - 1)
                return T{0};
            return mx[n - 1];
        }
        MonotonyQueue(size_t win):window{win}{}
        ~MonotonyQueue(){}
    };
}