#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define phb push_back
#define ppb pop_back
#define eb emplace_back
#define pp pop
#define ph push
#define ff first
#define ss second
#define htl(v, n) (v)+1,(v)+1+(n), greater<decltype(v[1])>()
#define lth(v, n) (v)+1,(v)+1+(n), less<decltype(v[1])>()
#define Max(a, b) ((a > b) ? a : b)
#define Min(a, b) ((a < b) ? a : b)
#define isZero(x) ((x)>0?(x):-(x)<eps)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define iFOR(it, begin, end) for(auto it = (begin); it!=(end);it++)
#define rFOR(i, a, b) for(int i = (a); i >= (b); i--)
#define vFOR(it, a) for(auto it = a.begin();it != a.end();it++)
#define aFOR(a, s) for(auto & (a) : (s))
#define pFOR(i, j, l, r, sit) for(int i = l,j = r; sit ;i++, j--)
#define DEBUG(x) cout << #x << " = " << (x) << endl
#define checktime() cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n" ; system("pause")
#define endl '\n'
#define faster_cpp_io() std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define setp(n) fixed<<setprecision(n)
#define cases(t,i) int t;cin >> t;for(int i = 1;i<=t;i++)

using pll = pair<long,long>;
using pii = pair<int,int>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using mll = map<ll, ll>;
using umll = unordered_map<ll, ll>;

constexpr ll mod = 1e5+7;
constexpr ll inf = 0x7f7f7f7f7f7f7f7f;
constexpr ld eps = 1e-9;
constexpr ll cap = 1e6+5;
const ld pi = acos(-1);