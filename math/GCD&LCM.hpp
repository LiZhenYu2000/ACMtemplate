#include <iostream>

namespace math{
    using ll = long long;

    ll gcd(ll a, ll b){
        return b ? gcd(b, a % b) : a;
    }

    ll lcm(ll a, ll b){
        ll g = gcd(a, b);
        return a * b / g;
    }
}