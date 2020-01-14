//Runtime: 120 ms, faster than 5.11% of C++ online submissions for Number of Longest Increasing Subsequence.
//Memory Usage: 44.6 MB, less than 11.11% of C++ online submissions for Number of Longest Increasing Subsequence.
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int res = 0;
		int ret = 0;
		int size = nums.size();
		vector<int> dp(size, 1);
		vector<vector<int>> tb(size, vector<int>(1, -1)); //trackback: record the pre position
		queue<int> q; //bfs to get the width(answer)

		if (size < 2) return size;

		int preMax;
		for (int i = 0; i < size; i++) {
			preMax = INT_MIN;
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (dp[j] > preMax) {
						preMax = dp[j];
						dp[i] = preMax + 1;
						tb[i].clear();
						tb[i].push_back(j);
					}
					else if (dp[j] == preMax) {
						tb[i].push_back(j);
					}
				}
			}
		}

		for (int i = 0; i < size; i++) {
			if (dp[i] > ret) {
				ret = dp[i];
			}
		}

		// cout << ret << endl;;
		for (int i = 0; i < size; i++) {
			if (dp[i] == ret) {
				// cout << "i:" << i << " dp:" << dp[i] << endl;
				q.push(i);
			}
		}

		q.push(-2);

		int front;
		while (q.size() > 0) {
			front = q.front();

			if (front == -2) {
				q.pop();
				q.push(-2);
				continue;
			}

			if (front == -1) {
				res = q.size() - 1;
				break;
			}

			q.pop();
			for (auto pre : tb[front])
				q.push(pre);
		}

		return res;
	}
};

//Runtime: 44 ms, faster than 38.78% of C++ online submissions for Number of Longest Increasing Subsequence.
//Memory Usage : 9.2 MB, less than 88.89% of C++ online submissions for Number of Longest Increasing Subsequence.
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int ans = 0;
		int ret = 0;
		int size = nums.size();
		vector<int> dp(size, 1);    //contain ith
		vector<int> sum(size, 1);  //contain ith
		int preMax;
		for (int i = 0; i < size; i++) {
			preMax = INT_MIN;
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (dp[j] > preMax) {
						preMax = dp[j];
						dp[i] = preMax + 1;
						sum[i] = sum[j];
					}
					else if (dp[j] == preMax) {
						sum[i] += sum[j];
					}
				}
			}
		}

		for (int i = 0; i < size; i++)  ret = max(dp[i], ret);

		for (int i = 0; i < size; i++)
			if (dp[i] == ret) ans += sum[i];

		return ans;
	}
};
