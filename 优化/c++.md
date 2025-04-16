[2370. 最长理想子序列](https://leetcode.cn/problems/longest-ideal-subsequence/)

```c++
class Solution {
public:
    int longestIdealString(string &s, int k) {
        int f[26]{};
        for (char c : s) {
            c -= 'a';
            f[c] = 1 + *max_element(f + max(c - k, 0), f + min(c + k + 1, 26));
        }
        return ranges::max(f);
    }
};
```



```c++
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long k = ranges::count(s, c);
        return k * (k + 1) / 2;
    }
};
        auto [l,r] = ranges::minmax(nums);

```

```c++
auto cmp = [&] (pair<int, int>&a, pair<int, int>b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minQ;
```

