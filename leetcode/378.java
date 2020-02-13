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

class Node {
    int row;
    int col;

    Node(int row, int col) {
        this.row = row;
        this.col = col;
    }
}
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Node> minHeap = new PriorityQueue<Node>((n1, n2) -> matrix[n1.row][n1.col] - matrix[n2.row][n2.col]);

        // put the 1st element of each row in the min heap
        // we don't need to push more than 'k' elements in the heap
        for (int i = 0; i < matrix.length && i < k; i++)
            minHeap.add(new Node(i, 0));

        // take the smallest (top) element form the min heap, if the running count is equal to k return the number
        // if the row of the top element has more elements, add the next element to the heap
        int numberCount = 0, result = 0;
        while (!minHeap.isEmpty()) {
            Node node = minHeap.poll();
            result = matrix[node.row][node.col];
            if (++numberCount == k)
                break;
            node.col++;
            if (matrix[0].length > node.col)
                minHeap.add(node);
        }
        return result;
    }
}