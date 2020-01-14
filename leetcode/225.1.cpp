class MyStack {
private:
	queue<int> d1;
	queue<int> d2;
	queue<int> *p1;
	queue<int> *p2;

public:
	/** Initialize your data structure here. */
	MyStack() {
		p1 = &d1;
		p2 = &d2;
	}

	/** Push element x onto stack. */
	void push(int x) {
		p2->push(x);
		while (!p1->empty()) {
			p2->push(p1->front());
			p1->pop();
		}

		queue<int> *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret = p1->front();
		p1->pop();
		return ret;
	}

	/** Get the top element. */
	int top() {
		return p1->front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return p1->empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */