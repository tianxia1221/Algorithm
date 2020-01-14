struct Node {
	int label;
	vector<Node*> to;
	Node(int label) : label(label) {}
};

class Solution {

private:
	enum STATE {
		WAIT,
		RUNNING,
		OVER
	};

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<Node*> graph(numCourses);
		vector<STATE> visit(numCourses, WAIT);

		constructGraph(graph, prerequisites);

		bool result;
		for (int i = 0; i < numCourses; i++) {
			if (visit[i] == WAIT) {
				result = dfs(graph, i, visit);
				if (result == false) return false;
			}
		}
		return true;
	}

	void constructGraph(vector<Node*> &graph, vector<vector<int>>& pre) {
		for (int i = 0; i < graph.size(); i++) {
			graph[i] = new Node(i);
		}

		for (int i = 0; i < pre.size(); i++) {
			graph[pre[i][1]]->to.push_back(graph[pre[i][0]]);
		}
	}

	bool dfs1(vector<Node*> &graph, int cur, vector<STATE> &visit) {
		bool result;
		visit[cur] = RUNNING;
		for (int i = 0; i < graph[cur]->to.size(); i++) {
			if (visit[graph[cur]->to[i]->label] == WAIT) {
				result = dfs(graph, graph[cur]->to[i]->label, visit);
				if (false == result) return false;
			}
			else if (visit[graph[cur]->to[i]->label] == RUNNING) {
				return false;
			}
		}
		visit[cur] = OVER;

		return true;
	}


    bool dfs(vector<Node*> &graph, int cur, vector<STATE> &visit){
        bool result;
        visit[cur] = RUNNING;
        int nextLable;
        for(int i=0; i<graph[cur]->to.size(); i++){
            nextLable = graph[cur]->to[i]->label;
            if(visit[nextLable] == WAIT) {
                result = dfs(graph, nextLable, visit);
                if(false == result) return false;
            }
            else if(visit[nextLable] == RUNNING){
                return false;
            }
        }
        visit[cur] = OVER;
        return true;
    }
};


