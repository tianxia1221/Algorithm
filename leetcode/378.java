//Runtime: 14 ms, faster than 58.76% of Java online submissions for Kth Smallest Element in a Sorted Matrix.
//        Memory Usage: 43.1 MB, less than 83.78% of Java online submissions for Kth Smallest Element in a Sorted Matrix.
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> maxQ = new PriorityQueue<>(k, new Comparator<Integer>(){
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });


        for(int i=0; i<matrix.length; i++) {
            for(int j=0; j<matrix.length; j++) {
                if(maxQ.size() < k) {
                    maxQ.add(matrix[i][j]);
                }
                else{
                    if(matrix[i][j] < maxQ.peek()) {
                        maxQ.remove();
                        maxQ.add(matrix[i][j]);
                    }
                }
            }
        }
        return maxQ.peek();
    }
}