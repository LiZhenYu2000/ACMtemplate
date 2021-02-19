namespace game{
    template<typename T>
    bool Bash(T n, T m){
        return (n % (m + 1)) ? true : false;
    }
}