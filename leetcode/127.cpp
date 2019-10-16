class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int ret = 0;
		map<string, vector<string>> graph;
		set<string> visited;
		wordList.push_back(beginWord);
		construct_graph(wordList, graph);
		ret = bfs(beginWord, endWord, graph, visited);
		return ret;
	}

	bool connect(string &word1, string &word2) {
		int count = 0;
		for (int i = 0; i < word1.size(); i++) {
			if (word1[i] != word2[i]) count++;
		}
		return count == 1;
	}

	void construct_graph(vector<string>& wordList, map<string, vector<string>>& graph) {
		for (int i = 0; i < wordList.size() - 1; i++) {
			for (int j = i + 1; j < wordList.size(); j++) {
				if (connect(wordList[i], wordList[j])) {
					graph[wordList[i]].push_back(wordList[j]);
					graph[wordList[j]].push_back(wordList[i]);
				}
			}
		}

	}

	int bfs(string &beginWord, string &endWord, map<string, vector<string>>& graph, set<string> &visited) {
		int ret = 0;
		queue<pair<string, int>> q;
		q.push(pair(beginWord, 1));
		visited.insert(beginWord);
		pair<string, int> cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (cur.first == endWord) return cur.second;
			for (int i = 0; i < graph[cur.first].size(); i++) {
				if (visited.find(graph[cur.first][i]) == visited.end()) {
					q.push(pair(graph[cur.first][i], cur.second + 1));
					visited.insert(graph[cur.first][i]);
				}
			}
		}
		return 0;
	}
};