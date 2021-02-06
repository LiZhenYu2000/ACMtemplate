namespace game{
    bool Bash(int n, int m){
        if (n % (m + 1))
        {
            return true;
        }
        return false;
    }
}