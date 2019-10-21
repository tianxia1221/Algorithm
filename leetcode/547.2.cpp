class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int ret = 0;
		int size = M.size();
		vector<bool> mark(size, false);

		for (int i = 0; i < size; i++) {
			if (mark[i] == false) {
				bfs(i, mark, M);
				ret++;
			}
		}
		return ret;
	}

	void bfs(int s, vector<bool> &mark, vector<vector<int>>& M) {
		queue<int> q;
		q.push(s);
		mark[s] = true;
		while (!q.empty()) {
			s = q.front();
			// mark[cur] = true;
			q.pop();
			for (int i = 0; i < M.size(); i++) {
				if (M[s][i] == 1 && mark[i] == false) {
					mark[i] = true;
					q.push(i);
				}
			}
		}
		return;
	}

};