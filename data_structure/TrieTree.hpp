#include <vector>
#include <string>

namespace data_strcuture
{
    using std::string;
    using std::vector;
    using ll = long long;
    class Trie{
    private:
        static const ll MAX_SIZE = 5e5;
        vector<vector<ll>> trie;
        ll sz;
        vector<ll> val;
    protected:
        ll idx(char c){
            return c - 'a';
        }
    public:
        ll search(const string& in, ll v = 0){
            ll u = 0, len = in.size() - 1;
            for(ll i = 0 ; i <= len ; i ++){
                ll c = idx(in[i]);
                if(!trie[u][c])
                    return -1;
                u = trie[u][c];
            }
            return val[u] += v;
        }
        ll search(string&& in, ll v = 0){
            return search(in, v);
        }
        ll search(const char* in, ll v = 0){
            return search(string(in), v);
        }
        void insert(const string& in, ll v = 0){
            ll u = 0, len = in.size() - 1;
            for(ll i = 0 ; i <= len ; i ++){
                ll c = idx(in[i]);
                if(!trie[u][c]){
                    val[sz] = 0;
                    trie[u][c] = sz ++;
                }
                u = trie[u][c];
            }
            val[u] = v;
        }
        void insert(string&& in, ll v = 0){
            insert(in, v);
        }
        void insert(const char* s, ll v = 0){
            insert(string(s), v);
        }
        Trie(size_t n = MAX_SIZE){
            sz = 1;
            trie.resize(n, vector<ll>(26, 0));
            val.resize(n, 0);
        }
    };
} // namespace data_strcuture
