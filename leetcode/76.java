class Solution {
    public String minWindow(String s, String t) {
        String ret = new String();
        int[] s_num = new int[128];
        int[] t_num = new int[128];
        int begin = 0;
        int len = Integer.MAX_VALUE;
        for (int i = 0; i < t.length(); i++) t_num[t.charAt(i)]++;

        for (int i = 0; i < s.length(); i++) {
            s_num[s.charAt(i)]++;
            while (begin < i) {
                if (t_num[s.charAt(begin)] == 0) begin++;
                else if (s_num[s.charAt(begin)] > t_num[s.charAt(begin)]) {
                    s_num[s.charAt(begin)]--;
                    begin++;
                } else {
                    break;
                }
            }
            if (is_ok_window(s_num, t_num)) {
                int size = i - begin + 1;
                if (len > size) {
                    len = size;
                    ret = s.substring(begin, i + 1);
                }
            }
        }
        return ret;
    }

    boolean is_ok_window(int[] s, int[] t) {
        for (int i = 0; i < t.length; i++) {
            if (s[i] < t[i]) return false;
        }
        return true;
    }
};