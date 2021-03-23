#pragma once
#include<algorithm>

namespace C_geometry{
    using f64 = double;
    using ll = long long;
    class BaseCM{
    public:
        static constexpr f64 eps = 1e-8;
        static constexpr ll INF64 = 0x3f3f3f3f3f3f3f3f;
        static constexpr ll _INF64 = 0xcfcfcfcfcfcfcfcf;
        inline bool isZero(f64 x){
            return (x > 0 ? x : (-x) < eps);
        }
        inline bool equal(f64 x, f64 y){
            return (abs(x - y) < eps);
        }
        inline bool lthan(f64 x, f64 y){
            return y - x > eps;
        }
        inline bool bthan(f64 x, f64 y){
            return x - y > eps;
        }
        BaseCM(){}
        ~BaseCM(){}
    };
}