#include <cmath>
#define min(a, b) ((a) < (b) ? (a) : (b))

namespace game{
    bool Wythoff(int a, int b){
        double r = (sqrt(5) + 1) / 2;
        int d = abs(a - b) * r;
        if (d != min(a, b))
        {
            return true;
        }
        return false;
    }
}