
namespace math {
    using ll = long long;
    
    ll phi(ll x){
        ll ans = x;
        for(ll i = 2 ; i * i <= x ; i ++){
            if(x % i == 0){
                ans = ans / i * (i - 1);
                while(x % i == 0){
                    x /= i;
                }
            }
        }
        if(x > 1)
            ans = ans / x * (x - 1);
        return ans;
    }

    ll fstp(ll a, ll b, ll mod){
        return ( (b == 0) ? 1 : ((b % 2) ? a % mod * fstp(a % mod * a % mod, b >> 1 , mod) : fstp(a % mod * a % mod, b >> 1 , mod)) ) % mod;
    }

    ll eulerdrop(ll a, ll b, ll mod = 1e18){
        ll en = phi(mod);
        return fstp(a, b % en + en, mod);
    }
}