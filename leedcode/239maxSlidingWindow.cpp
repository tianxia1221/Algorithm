//239. Sliding Window Maximum
//
//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
//For example,
//Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
//1 [3  -1  -3] 5  3  6  7       3
//1  3 [-1  -3  5] 3  6  7       5
//1  3  -1 [-3  5  3] 6  7       5
//1  3  -1  -3 [5  3  6] 7       6
//1  3  -1  -3  5 [3  6  7]      7
//Therefore, return the max sliding window as [3,3,5,5,6,7].
//
//Note:
//You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
//
//Follow up:
//Could you solve it in linear time?
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
/*
方法一：最直观的，每次从起点i遍历一遍窗口长度j = i, i + k，找最大值，两层for循环，时间复杂度O(n * k)
方法二：维护一个hash heap，每次移动，加入右边元素O(logk)，减去左边元素O(logk)，返回maxheap中的最大值O(1)，时间复杂度为O(n * logk)
使用Deque，维护一个递减的deque，时间复杂度为O(n)
已知 [1， 2， 7， 3， 8， 5， 3， 2]
[1], 2进入, 2 > 1 弹出1
[2], 7进入， 7 > 2 弹出2
[7], 第一个窗口最大值为7，3进入，3 < 7
[7, 3], 第二个窗口最大值为7，8进入， 8 > 3 弹出3
[7], 8 > 7, 弹出7
[8], 第三个窗口最大值为8
为什么要用deque呢？注意这种情况
当前为[9, 8, 7], 6进入，6 < 7, 6进入
[9, 8, 7, 6] 但是对K=3的窗口，必须要弹出9，这步就要用到deque*/

作者：Jason_Yuan
链接：http://www.jianshu.com/p/7662caf4f39c
來源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
