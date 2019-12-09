//Runtime: 8 ms, faster than 59.20% of C++ online submissions for Increasing Triplet Subsequence.
//Memory Usage: 9.1 MB, less than 52.94% of C++ online submissions for Increasing Triplet Subsequence.
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, big = INT_MAX;
        for(int n: nums) {
            if(n <= small)
                small = n;
            else if(n <= big)
                big = n;
            else
                return true;
        }

        return false;
    }
};