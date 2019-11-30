//Runtime: 4 ms, faster than 95.22% of C++ online submissions for Longest Common Prefix.
//Memory Usage: 10.1 MB, less than 6.45% of C++ online submissions for Longest Common Prefix.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if(l > r) return "";
        if(l == r) return strs[l];

        if(l == r-1) return merge(strs[l], strs[r]);

        int mid = l + (r - l)/2;
        string s1 = longestCommonPrefix(strs, l, mid);
        string s2 = longestCommonPrefix(strs, mid+1, r);
        return merge(s1,s2);

    }

    string merge(string &s1, string &s2) {
        string ans;
        int l = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        int pos = -1;
        while(l < n1 && l< n2 && s1[l] == s2[l]) {
            pos = l;
            l++;
        }

        if(l>=0) {
            return move(s1.substr(0, pos+1));
        }

        return "";
    }
};

//Runtime: 4 ms, faster than 95.22% of C++ online submissions for Longest Common Prefix.
//Memory Usage: 8.7 MB, less than 98.39% of C++ online submissions for Longest Common Prefix.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        char c;
        for(int i=0;i<strs[0].size();i++) {
            c = strs[0][i];
            for(int j=1;j<strs.size();j++) {
                if (strs[j][i] != c) return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};