class Solution {
    public boolean wordPattern(String pattern, String str) {
        HashMap<String, Character> map = new HashMap<>();
        HashSet<Character> set = new HashSet<>();
        Character c;
        StringBuilder sb = new StringBuilder();
        int j = 0;
        str += " ";

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                c = map.get(sb.toString());
                if (j > pattern.length() - 1) return false;
                if (c == null) {
                    c = pattern.charAt(j);
                    if (true == set.contains(c)) return false;
                    set.add(c);
                    map.put(sb.toString(), c);
                } else {
                    if (false == c.equals(pattern.charAt(j)))
                        return false;
                }
                sb.delete(0, sb.length());
                j++;
            } else {
                sb.append(str.charAt(i));
            }
        }

        if (j != pattern.length()) return false;

        return true;
    }
}