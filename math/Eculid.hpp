#include <iostream>

namespace math{
    int gcd(int a, int b){
        return b ? gcd(b, a % b) : a;
    }

    int lcm(int a, int b){
        int g = gcd(a, b);
        return a * b / g;
    }
}