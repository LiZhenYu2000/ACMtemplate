#include<cstdio>
#include<cctype>
#include<stack>
namespace basic{
    template<typename T>
    int read(T& result) { // fast read
        char ch;bool f{true};int w{1};
        result = 0;
        do{ ch = getchar();
            if (ch == EOF)
                return 0;
            else if (!isdigit(ch) && f){
                if (ch == '-')
                    w = -1;
                continue;
            }else if(isdigit(ch))
                result = result * 10 + (ch - '0'), f = false;
            else
                break;
        } while (1);
        result *= w;
        return 1;
    }
    template<typename T>
    void write (T x) { // fast output
        static std::stack<int> sta;
        bool positive = {(x >= 0)};
        do{
            sta.push(x % 10) , x /= 10;
        } while (x);
        if (!positive)
            putchar('-');
        while (!sta.empty())
            putchar(sta.top() + '0'), sta.pop();
    }
}