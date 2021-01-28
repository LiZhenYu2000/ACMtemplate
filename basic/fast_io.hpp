#include<cstdio>
#include<cctype>
#include<stack>
/*
struct my_EOF {
    const char* const text{"end of file"};
    void display(){
        printf(text);
    }
    my_EOF(){}
    my_EOF(const char* const t):text{t}{}
};
*/
namespace basic{
    template<typename T>
    decltype(EOF) read(T& result) { // fast read
        char ch;
        bool f{true};
        T w{1};
        result = 0;
        do{
            ch = getchar();
            if (ch == EOF)  return EOF;

            if (!isdigit(ch) && f)
            {
                if (ch == '-')
                {
                    w = -1;
                }
                continue;
            }
            else if (isdigit(ch))
            {
                result = result * 10 + (ch - '0');
                f = false;
            }
            else
                break;
        } while (1);
        result *= w;
        return 1;
    }
    template<typename T>
    void write (T x) { // fast output
        bool positive = {(x >= 0)};
        static std::stack<int> sta;
        do{
            sta.push(x % 10) , x /= 10;
        } while (x);
        if (!positive)
        {
            putchar('-');
        }
        while (!sta.empty())
        {
            putchar(sta.top() + '0');
            sta.pop();
        }
    }
}