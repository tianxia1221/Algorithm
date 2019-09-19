class Solution {
private:

public:
	int calculate(string s) {
		enum State { BEGIN, NUM, OPT };
		State state = BEGIN;
		stack<int> data;
		stack<char> sign;
		bool canComp = false;
		int num = 0;
		for (int i = 0; i < s.size(); i++) {
			if (' ' == s[i]) continue;
			switch (state) {
			case BEGIN:
				if ('0' <= s[i] && s[i] <= '9') {
					state = NUM;
				}
				// "("
				else {
					state = OPT;
				}
				i--;
				break;
			case NUM:
				if ('0' <= s[i] && s[i] <= '9') {
					num = num * 10 + (s[i] - '0');
				}
				else {
					data.push(num);
					if (canComp) compute(data, sign);
					state = OPT;
					i--;
					num = 0;
				}
				break;
			case OPT:
				if ('+' == s[i] || '-' == s[i]) {
					sign.push(s[i]);
					canComp = true;
				}
				else if ('(' == s[i]) {
					state = NUM;
					canComp = false;
				}
				else if (')' == s[i]) {
					compute(data, sign);
				}
				else if ('0' <= s[i] && s[i] <= '9') {
					state = NUM;
					i--;
				}
				break;
			default:
				break;
			}
		}

		if (num != 0) {
			data.push(num);
			compute(data, sign);
		}

		if (data.empty()) return 0;

		return data.top();
	}

	void compute(stack<int> &data, stack<char> &sign) {
		if (data.size() < 2 && sign.size() < 1) return;
		int data1 = data.top();
		data.pop();

		int data2 = data.top();
		data.pop();

		char opt = sign.top();
		sign.pop();

		data.push(opt == '+' ? data2 + data1 : data2 - data1);
	}

};