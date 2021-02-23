#include <vector>
using std::vector;

namespace graph_theory{

    class Graph
    {
        static constexpr long long MAX_N = 1e6;
        vector<long long> head;
        vector<long long> nxt;
        vector<long long> to;
        vector<long long> val;
        long long cnt;
    public:
        void add(long long u, long long v, long long w = 1){
            nxt[cnt] = head[u];
            head[u] = cnt;
            to[cnt] = v;
            val[cnt++] = w;
        }
        long long find_edge(long long u, long long v){
            long long i;
            for(i = head[u]; ~i; i = nxt[i]) {
                if(to[i] == v) {
                    return i;
                }
            }
            return i;
        }
        long long operator[](long long u){
            return head[u];
        }
        long long val_edge(long long idx){
            return val[idx];
        }
        long long next_edge(long long u){
            return nxt[u];
        }
        Graph(size_t n):head(n+1, -1),nxt(2*n+2, -1), to(2*n+2, -1), val(2*n+2, 0){}
        Graph(size_t n, size_t m):head(n+1, -1),nxt(2*m+2, -1), to(2*m+2, -1), val(2*m+2, 0){}
        Graph():head(MAX_N, -1),nxt(MAX_N, -1), to(MAX_N, -1), val(MAX_N, 0){}
        ~Graph(){}
    };
}