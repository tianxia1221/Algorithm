class MedianFinder {

    private PriorityQueue<Integer> smallQ;
    private PriorityQueue<Integer> bigQ;

    /** initialize your data structure here. */
    public MedianFinder() {
        smallQ = new PriorityQueue<Integer>();
        bigQ = new PriorityQueue<Integer>((Integer a, Integer b) -> b - a);
//         bigQ = new PriorityQueue<Integer>(new Comparator<Integer>(){
//             @Override
//             public int compare(Integer d1, Integer d2){
//                 // or return d2.compareTo(d1);
//                  return d2-d1;
//             }

//         });
    }

    public void addNum(int num) {
        int tmp;
        bigQ.add(num);
        smallQ.add(bigQ.remove());
        if(smallQ.size() - bigQ.size() > 1)
            bigQ.add(smallQ.remove());
    }

    public double findMedian() {
        if(bigQ.size() == smallQ.size())
            return ((double)bigQ.peek() + (double)smallQ.peek())/2;
        return smallQ.peek();
    }
}