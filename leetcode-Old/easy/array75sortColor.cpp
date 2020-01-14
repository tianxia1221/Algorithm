//75. Sort Colors
//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur=0, front=0, back=nums.size()-1;
        while(cur <= back){
            if(0==nums[cur]) swap(nums[front++], nums[cur++]);
            else if(2==nums[cur]) swap(nums[back--], nums[cur]);
            else cur++;
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur=0, front=0, back=nums.size()-1;
        while(cur <= back){
            if(0==nums[cur])
                if (cur==front) cur=++front;
                else swap(nums[front++], nums[cur++]);
                else if(2==nums[cur])
                    if(2==nums[back]) back--;
                    else swap(nums[back--], nums[cur]);
                    else cur++;
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start < end && nums[start] == 0 ) start++;
        if(start==end) return;
        
        while(start < end && nums[end] == 2 ) end--;
        if(start==end) return;
        
        int mid = start;
        while(mid <= end){
            if(nums[mid] == 2){
                swap(nums[mid], nums[end]);
                end--;
                while(mid < end && nums[end] == 2 ) end--;
            }
            else if(nums[mid] == 0){
                if(mid > start){
                    swap(nums[mid], nums[start]);
                    start++;
                }else{
                    mid++;
                    start++;
                }
                
            }
            else{
                mid++;
            }
        }
    }
    
};
