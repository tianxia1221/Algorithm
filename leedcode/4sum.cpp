//18. 4Sum
//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note: The solution set must not contain duplicate quadruplets.
//
//For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//A solution set is:
//[
// [-1,  0, 0, 1],
// [-2, -1, 1, 2],
// [-2,  0, 0, 2]
// ]
//
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> elm;
        int len = nums.size();
        int front,back,sum;
        sort(nums.begin(), nums.end());
        for(int i=0; i<len-3; i++){
            for(int j=i+1; j<len-2; j++){   //+j
                front = j+1;
                back = len-1;
                while(front < back){
                    sum = nums[i]+nums[j]+nums[front]+nums[back];  //+j
                    if(sum==target){
                        elm.clear();
                        elm.push_back(nums[i]);
                        elm.push_back(nums[j]);
                        elm.push_back(nums[front++]);
                        elm.push_back(nums[back--]);
                        ans.push_back(elm);
                        while(front < back && nums[front] == elm[2]) front++; //new position
                        while(front < back && nums[back] == elm[3]) back--;  //new position
                    }
                    else if(target<sum) back--;
                    else front++;
                }
                while(j<len-2 && nums[j+1] == nums[j] ) j++;
            }
            while(i<len-3 && nums[i+1] == nums[i] ) i++; //+j
        }
        return ans;
    }
    
};
