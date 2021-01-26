#include<cstdio>
#include<cstring>
namespace math {
    constexpr size_t MAX_NUM = 1e6;
    //线性筛法求质数
    int prime[MAX_NUM];
    bool Isprime[MAX_NUM];
    int get_primes(size_t n){
        int cnt=1;
        // prime[0]=2;
        Isprime[0]=Isprime[1]=1;
        for (size_t i = 2; i <= n; i++)
        {
            if (!Isprime[i])
            {
                prime[cnt++] = i;
            }
            for (size_t j = 1; prime[j] <= n / i; j++)
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