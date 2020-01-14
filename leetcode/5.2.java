//Runtime: 5 ms, faster than 97.03% of Java online submissions for Longest Palindromic Substring.
//        Memory Usage: 37.6 MB, less than 58.87% of Java online submissions for Longest Palindromic Substring.
class Solution {
    public String longestPalindrome(String s) {
        int ansCenter = 0;

        int n = s.length();
        if (n < 2) return s;

        StringBuilder sb = new StringBuilder(2 * n + 3);

        sb.append('@');
        sb.append('#');
        for (int i = 0; i < n; i++) {
            sb.append(s.charAt(i));
            sb.append('#');
        }
        sb.append('$');

        String str = sb.toString();
        int[] redius = new int[2 * n + 3];
        int center = 0, right = 0;
        int maxRedius = 0;
        for (int i = 2; i < str.length() - 2; i++) {

            if (i < right) {

                redius[i] = Math.min(redius[2 * center - i], right - i);
            }

            while (str.charAt(i + redius[i] + 1) == str.charAt(i - redius[i] - 1))
                redius[i]++;

            if (maxRedius < redius[i]) {
                maxRedius = redius[i];
                ansCenter = i;
            }

            if (right < i + redius[i]) {
                right = i + redius[i];
                center = i;
            }

        }

        int start = ansCenter - redius[ansCenter];
        int end = ansCenter + redius[ansCenter];

        start = (start + 1) / 2;
        end = (end - 1) / 2;

        return new String(s.substring(start - 1, end));

    }
}