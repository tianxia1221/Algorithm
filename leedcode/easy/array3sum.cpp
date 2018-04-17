//15. 3Sum
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
// [-1, 0, 1],
// [-1, -1, 2]
//]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> elm;
        int len = nums.size();
        int front,back,target;
        sort(nums.begin(), nums.end());
        for(int i=0; i<len-2; i++){
            front = i+1;
            back = len-1;
            while(front < back){
                target = nums[i]+nums[front]+nums[back];
                if(0==target){
                    elm.clear();
                    elm.push_back(nums[i]);
                    elm.push_back(nums[front++]);
                    elm.push_back(nums[back--]);
                    ans.push_back(elm);
                    while(front < back && nums[front] == elm[1]) front++;
                    while(front < back && nums[back] == elm[2]) back--;
                }
                else if(target>0) back--;
                else front++;
            }
            while(i<len-2 && nums[i+1] == nums[i] ) i++;
        }
        return ans;
    }
};

def threeSum(self, nums):
res = []
nums.sort()
for i in xrange(len(nums)-2):
if i > 0 and nums[i] == nums[i-1]:
continue
l, r = i+1, len(nums)-1
while l < r:
s = nums[i] + nums[l] + nums[r]
if s < 0:
l +=1
elif s > 0:
r -= 1
else:
res.append((nums[i], nums[l], nums[r]))
while l < r and nums[l] == nums[l+1]:
l += 1
while l < r and nums[r] == nums[r-1]:
r -= 1
l += 1; r -= 1
return res
