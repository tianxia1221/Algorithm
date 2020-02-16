class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        dp[0] = 0;

        List<Integer> squareList = new ArrayList<>();
        int cur=1 , i=1, minVal, pre;
        while(cur <= n) {
            squareList.add(cur);
            i++;
            cur = i*i;
        }

        for(i=1; i<=n; i++) {
            minVal= Integer.MAX_VALUE;
            for(int square: squareList) {
                pre = i - square;
                if(pre >=0 ) {
                    minVal = Integer.min(minVal, dp[pre]);
                }
                else {
                    break;
                }
            }

            dp[i] = minVal + 1;
        }

        return dp[n];
    }
}

class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        int cur, h;
        for(int i=1; i<=n; i++){
            h = 1;
            while(h*h <= i){
                cur = dp[i - h*h] + 1;
                if(cur < dp[i]) dp[i] = cur;
                h++;
            }
        }
        return dp[n];
    }

}