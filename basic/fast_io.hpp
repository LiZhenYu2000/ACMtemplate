#include<cstdio>
#include<cctype>
#include<stack>
namespace basic{
    template<typename T>
    int read(T& result) { // fast read
        char ch;int w = 1;
        result = 0;
        
        ch = getchar();
        while(ch != '-' && !(ch >= '0' && ch <= '9'))
            ch = getchar();

        if(ch == '-')
            w = -1;

        while(isdigit(ch)){
            result = result * 10 + (ch - '0');
            ch = getchar();
        }

        result *= w;
        return 1;
    }
    template<typename T>
    void write (T x) { // fast output
        string tmp;string tail = (x < 0) ? "-" : "";
        while(x){
            tmp += x % 10 + '0';
            x /= 10;
        }
        tmp += tail;
        reverse(tmp.begin(), tmp.end());
        cout << tmp << endl;
    }
}