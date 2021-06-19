namespace math{
    using ll = long long;
    using f64 = double;

    class Complex{
    public:
        f64 x, y;
        friend Complex operator + (Complex a, Complex b){
            return Complex(a.x + b.x, a.y + b.y);
        }
        friend Complex operator - (Complex a, Complex b){
            return Complex(a.x - b.x, a.y - b.y);
        }
        friend Complex operator * (Complex a, Complex b){
            return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
        }
        Complex(f64 a = 0.0, f64 b = 0.0):x{a}, y{b}{}
    };
    
    void FFT(ll limit, Complex* a, ll type){
        for(int i = 0; i <= limit - 1; i++)
            if(i < r[i])
                swap(a[i], a[r[i]]);
        for(int mid = 1; mid <= limit - 1; mid <<= 1){
            Complex W_n { cos(pi / mid), type * sin(pi / mid)};
            ll R = mid << 1;
            for(int j = 0; j <= limit - 1; j += R){
                Complex w(1, 0);
                for(int k = 0; k <= mid - 1; k ++){
                    Complex x = a[j + k],
                            y = w * a[j + mid + k];
                    a[j + k] = x + y;
                    a[j + mid + k] = x - y;
                    w = w * W_n;
                }
            }
        }
    }

}