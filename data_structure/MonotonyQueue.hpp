#include<deque>
#include<vector>
#include<algorithm>
#include<utility>
#define ss second
#define ff first
#define mp make_pair
namespace data_structure{
    using ll = long long;
    using std::deque;
    using std::pair;
    using std::make_pair;
    template<typename T>
    class MonotonyQueue
    {
    private:
        size_t window{10};
        size_t idx_max{0};
        size_t idx_min{0};
        deque<pair<T, size_t>> ic, dc;

        void test_front_max(size_t i){
            while(!dc.empty() && dc.front().ss < i)
                dc.pop_front();
        }
        
        void test_front_min(size_t i){
            while(!ic.empty() && ic.front().ss < i)
                ic.pop_front();
        }

        void insert_back_max(const T& num, size_t i){
            while(!dc.empty() && dc.back().ff < num)
                dc.pop_back();
            dc.push_back(mp(num, i));
        }
        
        void insert_back_min(const T& num, size_t i){
            while(!ic.empty() && ic.back().ff > num)
                ic.pop_back();
            ic.push_back(mp(num, i));
        }
    public:
        bool empty_mn(){
            return idx_min == 0;
        }
        bool empty_mx(){
            return idx_max == 0;
        }
        void insert_mx(ll num){
            insert_back_max(num, ++idx_max);
        }
        void insert_mn(ll num){
            insert_back_min(num, ++idx_min);
        }
        void insert(ll num){
            insert_mx(num);
            insert_mn(num);
        }
        void clear(){
            idx_max = 0, 
            idx_min = 0;
            ic.clear(), dc.clear();
        }
        pair<T, size_t> winMin(){
            if(idx_min > window)
                test_front_min(idx_min - window + 1);
            return ic.front();
        }
        pair<T, size_t> winMax(){
            if(idx_max > window)
                test_front_max(idx_max - window + 1);
            return dc.front();
        }
        MonotonyQueue(size_t win):window{win}{}
        MonotonyQueue(){}
        ~MonotonyQueue(){}
    };
}