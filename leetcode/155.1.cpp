class MinStack {
private:
	stack<int> data;
	stack<int> min;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		if (min.empty() || min.top() >= x)
			min.push(x);
	}

	void pop() {
		if (data.top() == min.top())
			min.pop();
		data.pop();
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return min.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */