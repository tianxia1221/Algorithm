//Runtime: 7 ms, faster than 69.59% of Java online submissions for Longest Palindromic Substring.
//        Memory Usage: 35.7 MB, less than 100.00% of Java online submissions for Longest Palindromic Substring.
class Solution {
    public String longestPalindrome(String s) {

        int n = s.length();
        if (n < 2) return s;

        int ans = 1;
        int lpos = 0, rpos = 0;

        int low = 0, high = 0;
        int count = 2 * n + 1;
        int left, right;

        int len;
        for (int i = 0; i < count; i++) {
            low = i / 2;
            high = low + i % 2;
            left = 0;
            right = 0;
            while (low >= 0 && high < n && low <= high) {
                if (s.charAt(low) == s.charAt(high)) {

                    left = low--;
                    right = high++;
                    continue;
                } else {
                    break;
                }
            }
            len = right - left + 1;
            if (len > ans) {
                ans = len;
                lpos = left;
                rpos = right;
            }
        }
        return new String(s.substring(lpos, rpos + 1));
    }
}