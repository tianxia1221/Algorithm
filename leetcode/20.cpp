//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
//Memory Usage: 8.4 MB, less than 96.90% of C++ online submissions for Valid Parentheses.

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (auto c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};