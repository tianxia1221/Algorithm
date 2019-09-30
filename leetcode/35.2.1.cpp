class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (right > left){
            mid = left+(right-left)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] > target) {
                mid == left? right = left:right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            }
        }

       // left = right; while false condition (left == right)

        // int ret = left;
        // if(nums[left] > target) {
        //     ret = left;
        // } else if(nums[left] < target) {
        //     ret = left+1;
        // }

        int ret = left;
        if(nums[left] < target) {
            ret = left+1;
        }

        return ret;
    }
};