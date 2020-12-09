namespace game{
    bool Bash(int n, int m){
        // 一堆n个物品，两个人轮流从中取出1~m个，最后取光者胜（不能继续的人输）
        if (n % (m + 1))
        {
            return true;
        }
        return false;
    }
}