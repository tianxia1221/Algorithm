class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ret = 0;
        int begin = 0, end = 0;
        Set<Character> set = new HashSet<>();
        while (end < s.length()) {
            if (set.contains(s.charAt(end))) {
                set.remove(s.charAt(begin++));
            } else {
                set.add(s.charAt(end++));
            }

            //ret = Math.max(ret, end-begin);
            ret = Math.max(ret, set.size());

        }
        return ret;
    }
}