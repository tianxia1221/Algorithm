//Runtime: 0 ms, faster than 100.00% of Java online submissions for Letter Combinations of a Phone Number.
//        Memory Usage: 36.3 MB, less than 98.63% of Java online submissions for Letter Combinations of a Phone Number.
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if(digits.length() == 0) return res;
        StringBuilder elm = new StringBuilder(digits.length());
        // Map<Character, String> phone = new HashMap<Character, String>() {{
        //   put('2', "abc");
        //   put('3', "def");
        //   put('4', "ghi");
        //   put('5', "jkl");
        //   put('6', "mno");
        //   put('7', "pqrs");
        //   put('8', "tuv");
        //   put('9', "wxyz");
        // }};

        // List<String> phone = new ArrayList<String>(){{add("abc"); add("ddd");}};
        List<String> phone = new ArrayList<String>(Arrays.asList("", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"));


        traceBack (digits, 0, elm, res, phone);
        return res;
    }

    void traceBack(String digits, int start, StringBuilder elm, List<String> res, List<String> phone){
        if(start == digits.length()) {
            res.add(elm.toString());
            return;
        }

        char c = digits.charAt(start);
        // if(c == '1') {
        //     traceBack(digits, start+1, elm, res, phone);
        //     return;
        // }

        String s = phone.get(c - '0');

        for(int i = 0; i<s.length(); i++) {
            elm.append(s.charAt(i));
            traceBack(digits, start+1, elm, res, phone);
            elm.deleteCharAt(elm.length()-1);
        }
    }

}

//Runtime: 1 ms, faster than 59.85% of Java online submissions for Letter Combinations of a Phone Number.
//Memory Usage: 36 MB, less than 98.63% of Java online submissions for Letter Combinations of a Phone Number.
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if(digits.length() == 0) return res;
        StringBuilder elm = new StringBuilder(digits.length());
        Map<Character, String> phone = new HashMap<Character, String>() {{
            put('2', "abc");
            put('3', "def");
            put('4', "ghi");
            put('5', "jkl");
            put('6', "mno");
            put('7', "pqrs");
            put('8', "tuv");
            put('9', "wxyz");
        }};
        traceBack (digits, 0, elm, res, phone);
        return res;
    }

    void traceBack(String digits, int start, StringBuilder elm, List<String> res, Map<Character, String> phone){
        if(start == digits.length()) {
            res.add(elm.toString());
            return;
        }

        char c = digits.charAt(start);
        if(c == '1') {
            traceBack(digits, start+1, elm, res, phone);
            return;
        }

        String s = phone.get(c);

        for(int i = 0; i<s.length(); i++) {
            elm.append(s.charAt(i));
            traceBack(digits, start+1, elm, res, phone);
            elm.deleteCharAt(elm.length()-1);
        }
    }

}