#include <bits/stdc++.h>

namespace math {
    using std::array;
    using std::vector;
    using ll = long long;
    class Prime
    {
    private:
        static constexpr size_t MAX_NUM = 1e7;
        vector<ll> prime;
        vector<short> Isprime;
        size_t cnt{0};
    public:
        void get_primes(size_t n){
            if(n == 0 || n >= MAX_NUM)  return ;
            for (size_t i = cnt == 0 ? 2 : prime[cnt - 1] + 1; i <= n; i++)
            {
                if (!Isprime[i])
                {
                    prime.emplace_back((ll)i);
                    cnt ++ ;
                }
                for (size_t j = 0; j < cnt &&  prime[j] * i <= n ; j++)
                {
                    Isprime[prime[j] * i] = true;
                    if (i % prime[j] == 0)
                    {
                        break;
                    }
                }
            }
        }
        size_t size(){
            return cnt;
        }
        bool is_prime(unsigned long long num){
            if(cnt == 0 || num > MAX_NUM || num == 1 || num == 0)
                return false;
            else if(num > prime[cnt - 1]){
                get_primes(num);
            }
            return !Isprime[num];
        }
        ll operator[](size_t pos){
            if(pos >= cnt) return 0;
            return prime[pos];
        }
        Prime():Isprime(MAX_NUM, false){}
        Prime(size_t n):Isprime(n, false){}
        ~Prime(){}
    };
}