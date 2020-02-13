class Solution {
public:
	int trap(vector<int>& height) {
		int sum = 0;
		trap(height, 0, height.size() - 1, sum);
		return sum;
	}

	void trap(vector<int>& height, int start, int end, int& sum) {
		if (end <= start + 1) return;

		int left = start + 1;
		int right = end - 1;
		//search left peak
		while (left <= end) {
			if (height[left] >= height[left - 1])
				left++;
			else
				break;
		}

		//search right peak;
		while (right >= left) {
			if (height[right] >= height[right + 1])
				right--;
			else
				break;

		}

		if (left > right) return;

		if (left > start) left--;
		if (right < end) right++;

		calulate(height, left, right, sum);
	}

	void calulate(vector<int>& height, int start, int end, int& sum) {
		int maxVal = height[start];
		if (height[end] < height[start]) {
			maxVal = height[end];
		}

		int left = start;
		int right = end;

		//Greedy
		if (maxVal == height[start]) {
			while (left < end && height[left] <= maxVal) {
				sum += maxVal - height[left];
				left++;
			}
		}
		else {
			while (right > left && height[right] <= maxVal) {
				sum += maxVal - height[right];
				right--;
			}
		}
		trap(height, left, right, sum);
	}
};

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int sum = 0;
		int minVal;
		while (left < right) {
			//search left peak
			if (height[left] <= height[left + 1]) {
				left++;
				continue;
			}

			//search right peak;
			if (height[right] <= height[right - 1]) {
				right--;
				continue;
			}

			minVal = min(height[left], height[right]);
			//Greedy
			if (minVal == height[left]) {
				while (left < right && height[left] <= minVal) {
					sum += minVal - height[left];
					left++;
				}
			}
			else {
				while (right > left && height[right] <= minVal) {
					sum += minVal - height[right];
					right--;
				}
			}

		}

		return sum;
	}
};

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int sum = 0;
		int minVal;
		while (left < right) {
			//             //search left peak
			//             if(height[left] <= height[left + 1]) {
			//                 left++; 
			//                 continue;
			//             }

			//             //search right peak;
			//             if(height[right] <= height[right - 1]) {
			//                 right--;
			//                 continue;
			//             }

			minVal = min(height[left], height[right]);
			//Greedy
			if (minVal == height[left]) {
				while (left < right && height[left] <= minVal) {
					sum += minVal - height[left++];
					//    left++;
				}
			}
			else {
				while (right > left && height[right] <= minVal) {
					sum += minVal - height[right--];
					//  right--;
				}
			}

		}

		return sum;
	}

};

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int sum = 0;
		int minVal;
		while (left < right) {
			minVal = min(height[left], height[right]);
			//Greedy
			if (minVal == height[left]) {
				while (left < right && height[left] <= minVal) {
					sum += minVal - height[left++];
				}
			}
			else {
				while (right > left && height[right] <= minVal) {
					sum += minVal - height[right--];
				}
			}

		}
		return sum;
	}
};