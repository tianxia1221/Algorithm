class Solution {
    public boolean wordPattern(String pattern, String str) {
        HashMap<String, Character> map = new HashMap<>();
        HashSet<Character> set = new HashSet<>();
        Character cVal;
        StringBuilder sb = new StringBuilder();
        int j = 0;
        str += " ";

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                cVal = map.get(sb.toString());
                if (j > pattern.length() - 1) return false;
                if (cVal == null) {
                    cVal = pattern.charAt(j);
                    if (true == set.contains(cVal)) return false;
                    set.add(cVal);
                    map.put(sb.toString(), cVal);
                } else {
                    if (false == cVal.equals(pattern.charAt(j)))
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