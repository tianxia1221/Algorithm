//Runtime: 4 ms, faster than 90.52% of C++ online submissions for Implement strStr().
//Memory Usage: 9.4 MB, less than 17.14% of C++ online submissions for Implement strStr().
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0, j = 0;
        int m = haystack.size();
        int n = needle.size();
        if(needle.empty()) return 0;

        vector<int> next(n, -1);
        kmp(needle, next);
        int t = m-n+1;
        while(i<t && j<n) {
            if(haystack[i+j] == needle[j]) {
                if(j == n-1) return i;
                j++;
                continue;
            }

          //or ok  if(next[j] != -1) {
            if(j>0) {
                //back i,j;
                i = i + j - next[j];
                j = next[j];
            }

            else {
                i++;
            }
        }

        return -1;
    }

    void kmp(string &s, vector<int>& next){
        next[0] = -1;
        int i = 1;
        int preMatchCount = -1;
        int n = s.length();
        while(i < n) {
            if(preMatchCount == -1) {
                next[i++] = 0;
                preMatchCount = 0;
                continue;
            }

            if(s[i-1] == s[preMatchCount]) {
                next[i] = preMatchCount + 1;
                preMatchCount++;
                i++;
            }
            else {
                preMatchCount = next[preMatchCount];
            }

        }
    }
};