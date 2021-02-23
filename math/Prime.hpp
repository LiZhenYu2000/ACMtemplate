#include <bits/stdc++.h>

namespace math {
    class Prime
    {
    private:
            static constexpr size_t MAX_NUM = 1e8;
            unsigned long long prime[MAX_NUM];
            bool Isprime[MAX_NUM];
            size_t cnt{0};
    public:
        size_t get_primes(unsigned long long n){
            if(n == 0)
                return 0;
            else if(n <= prime[cnt] || n >= MAX_NUM)
                return cnt;
            else{
                for (unsigned long long i = prime[cnt] + 1; i <= n; i++)
                {
                    if (!Isprime[i])
                    {
                        prime[++cnt] = i;
                    }
                    for (size_t j = 1; j <= cnt &&  prime[j] * i <= n ; j++)
                    {
                        Isprime[prime[j] * i] = true;
                        if (i % prime[j] == 0)
                        {
                            break;
                        }
                    }
                }
                return cnt;
            }
        }
        bool is_prime(unsigned long long num){
            if(num >= MAX_NUM)
                return false;
            else if(num > prime[cnt]){
                get_primes(num);
            }
            return Isprime[num];
        }
        Prime();
        ~Prime();
    };
    
}