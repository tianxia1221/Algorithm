//480. Sliding Window Median
//Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//
//Examples:
//[2,3,4] , the median is 3
//
//[2,3], the median is (2 + 3) / 2 = 2.5
//
//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
//
//For example,
//Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
//Window position                Median
//---------------               -----
//[1  3  -1] -3  5  3  6  7       1
//1 [3  -1  -3] 5  3  6  7       -1
//1  3 [-1  -3  5] 3  6  7       -1
//1  3  -1 [-3  5  3] 6  7       3
//1  3  -1  -3 [5  3  6] 7       5
//1  3  -1  -3  5 [3  6  7]      6
//Therefore, return the median sliding window as [1,-1,-1,3,5,6].
//
//Note:
//You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
//


/*最naive的方式就是在k个窗口内排序就好，这里不解释（因为开销很大啊，(n-k+1) * (k*log(k))。。

这里的方法是使用两个优先队列，即出队列的顺序是按照某种排好序的方式进行的。
所以我们设立两个优先队列，这里叫做堆吧：
1、最大堆，值大的先出来
2、最小堆：值小的先出来

那么回到我们的问题，我们想想如何确定中位数：
1、假设我们有上述最大堆，最小堆
2、如果我们把进入的所有值较小的一半放到最大堆，较大的一半放到最小堆中，那么较小的那一半poll出来的，和较大那一半poll出来的，不正好是k个窗口的中位数的候选值么？
3、按照上面那个思想，我们就行动，再输入值得时候，根据其大小，放入最大堆或者最小堆中，然后调整一些大小，保证最大堆那边的大小等于或者多一个于最小堆
4、当输出的时候，也就是从最大堆取一个，或者双方各取一个就可以计算了
5、删除的时候，在对应的堆中删除，再按照3中的方式更新下就好*/

public class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int m = n - k + 1; // 结果的尺寸
        double[] res = new double[m];
        //两个堆，一个最大堆，一个最小
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(k, Collections.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(k);
        for ( int i=0; i<n; i++){
            int num = nums[i];
            // 让maxHeap始终保存小于一半的值，minHeap保存大于一半的，正好两半
            if( maxHeap.size() == 0 || maxHeap.peek() >= num)
                maxHeap.add(num);
            else minHeap.add(num);
            // 维护两个堆，保证两个堆得大小，要么保持一致（偶数时），要么maxHeap多一个（奇数时）
            if( minHeap.size() > maxHeap.size() )
                maxHeap.add(minHeap.poll());
            if( maxHeap.size() > minHeap.size() + 1 )
                minHeap.add(maxHeap.poll());
            // 如果需要输出
            if ( i-k+1 >=0 ){
                if( k % 2 == 1 )
                    res[i- k + 1] = maxHeap.peek();
                else
                    res[i- k + 1] = (maxHeap.peek()/2.0 + minHeap.peek()/2.0); // 小心溢出
                //移除并更新
                int toBeRemove = nums[i - k + 1];
                if( toBeRemove <= maxHeap.peek())
                    maxHeap.remove(toBeRemove);
                else minHeap.remove(toBeRemove);
                // 维护两个堆，保证两个堆得大小，要么保持一致（偶数时），要么maxHeap多一个（奇数时）
                if( minHeap.size() > maxHeap.size() )
                    maxHeap.add(minHeap.poll());
                if( maxHeap.size() > minHeap.size() + 1 )
                    minHeap.add(maxHeap.poll());
                
            }
        }
        return res;
        
    }
}
