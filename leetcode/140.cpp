class Solution {
    unordered_map<string, vector<string>> cache;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return dp(s, wordDict);
    }

    vector<string> dp(string s, vector<string>& m){
        vector<string> ret;
        vector<string> rightRet;
        if(cache.find(s) != cache.end()) {
            return cache[s];
        }

        string right;
        for (string word : m) {
            if(s.substr(0, word.size())!=word) {
                continue;
            }

            right = s.substr(word.size());
            
            if(right.empty()) {
                ret.push_back(word);
                continue;
            }

            rightRet = dp(right, m);
            if(rightRet.size() != 0){
                 for(string str: rightRet) {
                    ret.push_back(word + " " + str);
                }
            }
        }

        cache[s] = ret;
        return ret;
    }
};