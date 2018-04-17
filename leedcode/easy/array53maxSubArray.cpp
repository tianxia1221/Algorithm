//53. Maximum Subarray
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//
//click to show more practice.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int soFar = 0;
        for(int i=0; i<nums.size(); i++){
            soFar = max(nums[i],nums[i]+soFar);
            ans = max(ans, soFar);
        }
        return ans;
    }
};
