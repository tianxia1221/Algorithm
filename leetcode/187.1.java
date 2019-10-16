class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> ret = new ArrayList<>();

        Map<String, Integer> mp = new HashMap<>();

        for (int i = 0; i < s.length() - 9; i++) {
            String word = s.substring(i, i + 10);
            if (mp.containsKey(word) == false) {
                mp.put(word, new Integer(1));
            } else {
                mp.put(word, mp.get(word) + 1);
            }
        }

        for (String key : mp.keySet()) {
            if (mp.get(key) > 1) ret.add(key);
        }
        return ret;
    }
}