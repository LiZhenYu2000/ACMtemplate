#include<cstdio>
#include<cstring>
namespace math {
    //朴素筛法求质数
    int prime[10005] = {0,1};
    bool Isprime[10005];
    int get_primes(size_t n){
        int cnt=1;
        Isprime[0]=Isprime[1]=1;
        for (size_t i = 2; i <= n; i++)
        {
            if (!Isprime[i])
            {
                prime[cnt++] = i;
            }
            for (size_t j = 0; prime[j] <= n / i; j++)
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