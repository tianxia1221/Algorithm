//Runtime: 16 ms, faster than 96.03% of C++ online submissions for Container With Most Water.
//Memory Usage: 9.8 MB, less than 68.04% of C++ online submissions for Container With Most Water.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, cur;
        int l = 0;
        int r = height.size() - 1;

        while(l < r) {
            cur = min(height[l], height[r]) * (r - l);
            ans = max(ans, cur);
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};