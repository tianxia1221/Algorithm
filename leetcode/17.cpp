//Runtime: 4 ms, faster than 60.26% of C++ online submissions for Letter Combinations of a Phone Number.
//Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string elm;
        if(digits.empty()) return res;
        help(res, elm, digits, 0);
        return res;
    }
    void help(vector<string> &res,string & elm, string &digits, int start) {
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(start == digits.length()){
            res.push_back(elm);
            return;
        }
        int a = digits[start] - '0';
        string strArr = v[a];
        for(int i=0; i<strArr.length() ; i++){
            elm.push_back(strArr[i]);
            help(res,elm,digits,start+1);
            elm.pop_back();
        }
        return;
    }
};