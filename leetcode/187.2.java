class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int[] map = new int[256];
        map['A'] = 0;
        map['C'] = 1;
        map['G'] = 2;
        map['T'] = 3;
        char[] map1 = new char[]{'A', 'C', 'G', 'T'};

        List<String> ret = new ArrayList<>();
        int[] memo = new int[1048576];

        int num = s.length() - 9;
        String word;
        for (int i = 0; i < num; i++) {
            word = s.substring(i, i + 10);
            change_word_to_int(word, memo, map);
        }

        for (int i = 0; i < 1048576; i++) {
            if (memo[i] > 1) {
                word = change_int_to_word(i, map1);
                ret.add(word);
            }
        }
        return ret;
    }

    void change_word_to_int(String word, int[] memo, int[] map) {
        int value = 0;
        for (int i = 9; i >= 0; i--) {
            value = (value << 2) + map[word.charAt(i)];
        }
        memo[value]++;
    }

    String change_int_to_word(int value, char[] map) {
        int index = 0;
        String word = new String();
        for (int i = 0; i < 10; i++) {
            index = value & 3;
            value = value >> 2;
            word += map[index];
        }
        return word;
    }
}