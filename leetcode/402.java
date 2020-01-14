class Solution {
    public String removeKdigits(String num, int k) {

        ArrayList<Character> s = new ArrayList<Character>();
        Character cur;
        for (int i = 0; i < num.length(); i++) {
            cur = num.charAt(i);
            while (s.size() != 0 && s.get(s.size() - 1) > cur && k > 0) {
                s.remove(s.size() - 1);
                k--;
            }

            if (s.size() == 0 && cur == '0') {
                //do nothing;
            } else {
                s.add(num.charAt(i));
            }
        }

        while (k > 0 && s.size() != 0) {
            s.remove(s.size() - 1);
            k--;
        }

        StringBuilder sb = new StringBuilder();
        for (Character c : s) {
            sb.append(c);
        }
        String result = sb.toString();

        // String result = new String();
        // for(Character c: s) {
        //     result = result  + String.valueOf(c);
        // }

        if (result.length() == 0) return "0";

        return result;
    }
}