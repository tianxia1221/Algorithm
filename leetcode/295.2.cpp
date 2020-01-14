class MedianFinder {
	priority_queue<int> bigQ;
	priority_queue<int, vector<int>, greater<int>> smallQ;
public:
	/** initialize your data structure here. */
	MedianFinder() {
	}

	void addNum(int num) {
		if (bigQ.size() == 0) {
			bigQ.push(num);
			return;
		}
		if (bigQ.size() == smallQ.size()) {
			if (bigQ.top() < num) smallQ.push(num);
			else bigQ.push(num);
		}

		else if (bigQ.size() > smallQ.size()) {

			if (bigQ.top() < num) {
				smallQ.push(num);
			}
			else {
				smallQ.push(bigQ.top());
				bigQ.pop();
				bigQ.push(num);
			}
		}
		else {
			//bigQ.size() <  smallQ.size()
			if (smallQ.top() > num) bigQ.push(num);
			else {
				bigQ.push(smallQ.top());
				smallQ.pop();
				smallQ.push(num);
			}

		}

	}

	double findMedian() {

		if (bigQ.size() == smallQ.size()) {
			//or return double(bigQ.top() + smallQ.top()) / 2;
			return double(bigQ.top() + smallQ.top()) / 2;
		}

		return bigQ.size() > smallQ.size() ? bigQ.top() : smallQ.top();
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */