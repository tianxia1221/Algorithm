class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        ret[0] = searchLeft(nums, target);
        ret[1] = searchRight(nums, target);
        return ret;
    }

    int searchLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (right >= left){
            mid = left+(right-left)/2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid-1] < target) return mid;
                right = mid - 1;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            }
        }
        return -1;
    }

    int searchRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (right >= left){
            mid = left+(right-left)/2;
            if(nums[mid] == target){
                if (mid == nums.size() - 1 || (target < nums[mid + 1])) return mid;
                left = mid + 1;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            }
        }
        return -1;
    }
};