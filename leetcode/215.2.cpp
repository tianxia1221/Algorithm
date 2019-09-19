class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return KthLargestInternal(nums, k, 0, nums.size() - 1);
	}
private:
	int KthLargestInternal(vector<int>& nums, int k, int low, int high) {
		int pivot = rand() % (high - low + 1) + low;  // choose random pivot ans swap with first element in array[low..high]
		swap(nums[low], nums[pivot]);
		int i = low + 1, j = high;
		while (i <= j) {
			if (nums[i] < nums[low]) {          // keep on putting elements less than pivot to the end of current array
				swap(nums[i], nums[j]);
				j--;
			}
			else {
				i++;                            // bigger elements remain at the front of the array
			}
		}
		swap(nums[low], nums[j]);               // put the pivot in right place after partition
		if (j - low == k - 1) {
			return nums[j];                     // if pivot is in the required position return it.
		}
		if (k - 1 < j - low) {
			return KthLargestInternal(nums, k, low, j - 1);     // if required order is less than pivot recurse to left half
		}
		else {
			return KthLargestInternal(nums, k - (j - low + 1), j + 1, high);  // if required order is greater recurese to right half
		}
	}
};