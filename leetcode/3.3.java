//Runtime: 2 ms, faster than 99.82% of Java online submissions for Longest Substring Without Repeating Characters.
//        Memory Usage: 36.8 MB, less than 99.76% of Java online submissions for Longest Substring Without Repeating Characters.
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n<2) return n;
        int ans = 0;
        int pre = 0;
        int count = 0;
        for(int i=1; i<s.length(); i++) {
            for(int j=pre; j<i; j++){
                if(s.charAt(i) == s.charAt(j)) {
                    pre = j+1;
                    break;
                }
            }
            count = i - pre + 1;
            if(count > ans) ans = count;
        }
        return ans;
    }
}
//
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        int[] index = new int[128]; // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            i = Math.max(index[s.charAt(j)], i);
            ans = Math.max(ans, j - i + 1);
            index[s.charAt(j)] = j + 1;
        }
        return ans;
    }
}