//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate Parentheses.
//Memory Usage: 13.7 MB, less than 88.43% of C++ online submissions for Generate Parentheses.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s(2*n, 0);
        s.resize(2*n);
        helper(n, n, s, res);
        return res;
    }

    void helper(int left, int right, string &s, vector<string>& res) {
          if(left== 0 && right == 0) {
              res.push_back(s);
              return;
          }

          int index = s.size() - left - right;
          if(left > 0){
              s[index] = '(';
              helper(left-1, right, s, res);

          }

         if(right>left) {
              s[index] = ')';
              helper(left, right-1, s, res);

         }
    }
};

//Runtime: 8 ms, faster than 54.35% of C++ online submissions for Generate Parentheses.
//Memory Usage: 13.9 MB, less than 86.78% of C++ online submissions for Generate Parentheses.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        helper(n, n, s, res);
        return res;

    }

    void helper(int left, int right, string &s, vector<string>& res) {
          if(left== 0 && right == 0) {
              res.push_back(s);
              return;
          }

          if(left > 0){
              s.push_back('(');
              helper(left-1, right, s, res);
              s.pop_back();
          }

         if(right>left) {
              s.push_back(')');
              helper(left, right-1, s, res);
              s.pop_back();
         }
    }
};