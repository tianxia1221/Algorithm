struct Node {
	int label;
	vector<Node*> to;
	Node(int label) : label(label) {}
};

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<Node*> graph(numCourses);
		vector<int> degree(numCourses, 0);

		constructGraph(graph, prerequisites, degree);

		bool result;
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (degree[i] == 0) {
				q.push(i);

			}
		}

		int front;
		int to;
		int size;
		while (!q.empty()) {
			front = q.front();
			q.pop();
			size = graph[front]->to.size();
			for (int i = 0; i < size; i++) {
				to = graph[front]->to[i]->label;
				degree[to]--;
				if (0 == degree[to]) q.push(to);
			}
		}

		for (auto i : degree) {
			if (0 != i) return false;
		}

		return true;
	}

	void constructGraph(vector<Node*> &graph, vector<vector<int>>& pre, vector<int> &degree) {
		for (int i = 0; i < graph.size(); i++) {
			graph[i] = new Node(i);
		}

		for (int i = 0; i < pre.size(); i++) {
			graph[pre[i][1]]->to.push_back(graph[pre[i][0]]);
			degree[pre[i][0]]++;
		}
	}
};


