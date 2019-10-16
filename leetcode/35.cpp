class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (right >= left){
            mid = left+(right-left)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] > target) {
                if(mid == 0) return mid;
                if(target > nums[mid-1])  return mid;

                right = mid - 1;

            } else if(nums[mid] < target ) {
                if(mid == nums.size()-1) return mid+1;
                if(target < nums[mid+1])  return mid+1;

                left = mid + 1;
            }
        }

        return nums[0];
    }
};
