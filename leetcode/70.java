class Solution {
    public int climbStairs(int n) {
        if(n < 3) return n;

        int prePre = 1;
        int pre = 2;
        int cur = 0;

        for(int i=3; i<=n; i++){
            cur = pre + prePre;
            prePre = pre;
            pre = cur;
        }

        return cur;
    }
}