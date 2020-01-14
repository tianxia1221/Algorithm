class Solution {
    public int longestPalindrome(String s) {
        boolean hasCenter = false;
        int ret = 0;
        int[] count = new int[256];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i)]++;
        }

        for (int i : count) {
            ret += (i / 2) * 2;
            if (i % 2 == 1) hasCenter = true;
        }

        if (hasCenter == true)
            ret++;

        return ret;
    }
}