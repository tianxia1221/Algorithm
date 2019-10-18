class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int ret = 0;
		int size = nums.size();
        vector<int> dp;
        int last;

        if(size < 2) return size;
        dp.push_back(nums[0]);

		for (int i = 1; i < size; i++) {
            last = dp[dp.size()-1];

            if(nums[i] == last) continue;

            if(nums[i] > last) dp.push_back(nums[i]);
            else {
                for (int j = 0; j < dp.size(); j++) {
                    if (nums[i] > dp[j] ) {
                        continue;
                    }
                    else if(nums[i] == dp[j] ){
                        break;
                    }
                    else{
                        dp[j] = nums[i];
                        break;
                    }
                }
            }
		}

		return dp.size();
	}
};