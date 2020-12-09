#include<cstdio>

int prime[10005];
bool Isprime[10005];
int cnt=1;
 //朴素筛法求质数
void get_primes(){
    Isprime[0]=Isprime[1]=1;
    for(int i=2;i<=10000;i++)
         Isprime[i]=1;
 
    for(int i=2;i<=10000;i++){
        if(Isprime[i])
             prime[cnt++]=i;
        for(int j=1;j<cnt&&prime[j]*i<=10000;j++){
               Isprime[prime[j]*i]=0;
               if(i%prime[j]==0)
                   break;
        }
    }
 
}