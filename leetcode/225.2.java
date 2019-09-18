class MyStack {
    private Queue<Integer> data1;
    //private Queue<Integer> data2;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        data1 = new LinkedList<Integer>();
        //   data2 = new LinkedList<Integer>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
//         data2.add(x);
// //         for(int i = 0; i<data1.size(); i++){
// //             data2.add(data1.poll());
// //         }
//         while(data1.size() > 0) {
//             data2.add(data1.poll());
//         }
//         Queue<Integer> tmp = data1;
//         data1 = data2;
//         data2 = tmp;

        data1.add(x);
        int len = data1.size() - 1;
        while (len > 0) {
            data1.add(data1.poll());
            len--;
        }

    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return data1.poll();
    }

    /**
     * Get the top element.
     */
    public int top() {
        return data1.peek();
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        //  System.out.println("eee:" + data1.size() );
        return data1.size() == 0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */