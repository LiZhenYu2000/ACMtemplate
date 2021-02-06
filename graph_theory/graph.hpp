#include <vector>

namespace graph_theory{
    constexpr long long MAX_N = 1e6;

    class graph
    {
        vector<long long> head;
        vector<long long> nxt;
        vector<long long> to;
        long long cnt;
    public:
        void add(long long u, long long v){
            nxt[++cnt] = head[u];
            head[u] = cnt;
            to[cnt] = v;
        }
        void find_edge(long long u, long long v){
            for(long long i = head[u]; ~i; i = nxt[i]) {
                if(to[i] == v) {
                    return true;
                }
            }
            return false;
        }
        void operator[](long long u){
            return head[u];
        }
        void next_edge(long long u){
            return nxt[u];
        }
        graph(size_t n):head(n+1, -1),nxt(n+1, -1), to(n+1, -1), cnt{-1}{}
        graph():head(MAX_N, -1),nxt(MAX_N, -1), to(MAX_N, -1), cnt{-1}{}
        ~graph(){}
    };
}