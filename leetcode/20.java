//Runtime: 1 ms, faster than 98.85% of Java online submissions for Valid Parentheses.
//        Memory Usage: 34.4 MB, less than 100.00% of Java online submissions for Valid Parentheses.
class Solution {
    public boolean isValid(String s1) {
        Stack<Character> s = new Stack<>();
        char c;
        for(int i=0; i<s1.length(); i++) {
            switch(c = s1.charAt(i)) {
                case '{':
                case '[':
                case '(':
                    s.push(c);
                    break;
                case '}':
                    if(s.empty() || s.peek() != '{')
                        return false;
                    else
                        s.pop();
                    break;
                case ')':
                    if(s.empty() || s.peek() != '(')
                        return false;
                    else
                        s.pop();
                    break;

                case ']':
                    if(s.empty() || s.peek() != '[')
                        return false;
                    else
                        s.pop();
                    break;
                default:
                    break;
            }

        }
        return s.empty();
    }
}

//Runtime: 2 ms, faster than 58.79% of Java online submissions for Valid Parentheses.
//        Memory Usage: 34.5 MB, less than 100.00% of Java online submissions for Valid Parentheses.
class Solution {
    public boolean isValid(String s) {
        Map<Character, Character> hm = new HashMap<Character, Character>(){{
            put(')', '(');
            put('}', '{');
            put(']', '[');
        }};
        char c;
        Stack<Character> stack = new Stack<Character>();
        for(int i=0; i<s.length(); i++) {
            c = s.charAt(i);
            if(hm.containsKey(c)) {
                if(stack.empty() || stack.peek() != hm.get(c))
                    return false;
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
}