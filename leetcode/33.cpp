class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (right >= left){
            mid = left+(right-left)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] > target) {

                //rotation in right
                if(nums[left] <= nums[mid]){
                    if(target >= nums[left])
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                //rotation in left
                else {
                    right = mid - 1;
                }

            } else if(nums[mid] < target ) {
                //rotation in left
                if(nums[mid] <= nums[right]){
                    if(target <= nums[right]){
                        left = mid + 1;
                    }
                    else
                        right = mid - 1;
                }
                else {
                        left = mid + 1;
                }
            }
        }

        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (right >= left){
            mid = left+(right-left)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] > target) {
                
                //rotation in right
                if(nums[left] <= nums[mid] && target < nums[left])
                    left = mid + 1;            
                else 
                    right = mid - 1;
                            
            } else if(nums[mid] < target ) {                
                //rotation in left
                if(nums[mid] <= nums[right] && target > nums[right])
                    right = mid - 1;
                else 
                    left = mid + 1;            
            }
            
        }
        return -1;
    }
};
