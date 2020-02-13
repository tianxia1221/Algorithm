class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> elm;
        dfs(ret, elm, s, 0);
        return ret;
    }
    
private:
    void dfs(vector<vector<string>>& ret, vector<string>& elm, string& s, int pos)
    {
        int n = s.size();
        if (pos == n)
        {
            ret.push_back(elm);
            return;
        }
        for (int i = pos; i < n; ++i)
        {
            if(isP(s, pos, i))
            {
                elm.push_back(s.substr(pos, i-pos+1));
                dsf(ret, elm, s, i+1);
                elm.pop_back();
            }
        }
    }
    bool isP(string& str, int start, int end)
    {
        while (start < end && str[start] == str[end])
        {
            ++start;
            --end;
        }
        
        return (start >= end);
    }
};