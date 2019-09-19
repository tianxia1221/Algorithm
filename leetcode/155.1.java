class MinStack {

    private Stack<Integer> data;
    private Stack<Integer> min;

    /**
     * initialize your data structure here.
     */
    public MinStack() {
        data = new Stack<Integer>();
        min = new Stack<Integer>();
    }

    public void push(int x) {
        if (min.empty() || min.peek() >= x)
            min.push(x);
        data.push(x);
    }

    public void pop() {
        if (min.peek().equals(data.peek())) {
            min.pop();
        }
        data.pop();
    }

    public int top() {
        return data.peek();
    }

    public int getMin() {
        return min.peek();
    }
}