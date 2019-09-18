//80. Remove Duplicates from Sorted Array II
//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//For example,
//Given sorted array nums = [1,1,1,2,2,3],
//
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
//
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size() ;
        if(!len) return 0;
        if(1==len) return 1;
        
        int ready = 0;
        int count = 1;
        for(int i=1; i<len; i++){
            if(nums[i] == nums[ready]) {
                count++;
                if(count>2){
                    continue;
                }
            }
            else{
                count = 1;
            }
            if(ready!= i) nums[++ready] = nums[i];
            else ready++;
        }
        return ready+1;
    }
};

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
