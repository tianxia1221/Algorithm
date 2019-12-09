
//Runtime: 60 ms, faster than 52.42% of C++ online submissions for First Unique Character in a String.
//Memory Usage: 13.1 MB, less than 39.06% of C++ online submissions for First Unique Character in a String.
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto &c : s) {
            m[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};

//Runtime: 36 ms, faster than 92.31% of C++ online submissions for First Unique Character in a String.
//Memory Usage: 12.9 MB, less than 68.75% of C++ online submissions for First Unique Character in a String.
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(256, 0);
        for(int i=0; i<s.length(); i++) {
            count[s[i]]++;
        }

        for(int i=0; i<s.length(); i++) {
            if(count[s[i]] == 1)
                return i;
        }

        return -1;

    }
};