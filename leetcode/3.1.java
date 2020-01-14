class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ret = 0;
        int[] memo = new int[256];
        int begin = 0;
        for (int i = 0; i < s.length(); i++) {
            memo[s.charAt(i)]++;
            while (memo[s.charAt(i)] != 1) {
                memo[s.charAt(begin++)]--;
            }

            if (i - begin + 1 > ret) ret = i - begin + 1;
        }
        return ret;
    }
}