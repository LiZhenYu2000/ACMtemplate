#include<stack>
#include<vector>

namespace data_structure{
    using std::vector;
    using std::stack;
    using std::pair;
    template<typename T>
    class MonotonyStack
    {
    private:
        stack<pair<T, size_t>> item;
        vector<size_t> ans;
    public:
        vector<size_t> build_ms(vector<T>& num, size_t n){
            for(size_t i = 0; i < n; i++){
                if(!item.empty()) {
                    while(!item.empty() && num[i]>item.top().first){
                            ans[item.top().second] = i+1;
                            item.pop();
                    }
                }
                item.push(std::pair<T, size_t>(num[i], i));
            }
            while(!item.empty()){
                ans[item.top().second] = 0;
                item.pop();
            }
            return ans;
        }
        MonotonyStack(vector<T>& num, size_t n):ans(n){
            build_ms(num, n);
        }
        MonotonyStack(vector<T>&& num, size_t n):MonotonyStack(num, n){}
        MonotonyStack(const T* num, size_t n):MonotonyStack(vector<T>(num, num + n)){}
        MonotonyStack(){}
        ~MonotonyStack(){}
    };
}