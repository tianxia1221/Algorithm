class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> ret;
		map<string, vector<string>> graph;
		map<string, int> visited;
		auto index = std::find(wordList.begin(), wordList.end(), beginWord);
		if (index == wordList.end()) wordList.push_back(beginWord);
		construct_graph(wordList, graph);
		bfs(endWord, beginWord, graph, visited, ret);
		return ret;
	}

	int bfs(string &beginWord, string &endWord, map<string, vector<string>>& graph, map<string, int> &visited, vector<vector<string>> &ret) {
		vector<string> item;
		vector<tuple<string, int, int>> q;
		q.push_back(tuple(beginWord, 1, -1));
		visited.insert(pair(beginWord, 1));
		tuple<string, int, int> cur;

		int minLen = INT_MAX;
		bool isfind = false;

		int j = 0;

		string key;
		int step;
		int pos;

		while (j < q.size()) {
			cur = q[j];

			key = get<0>(cur);
			step = get<1>(cur);
			pos = get<2>(cur);

			if (step > minLen) break;

			if (key == endWord) {
				if (false == isfind) {
					minLen = get<1>(cur);
					isfind = true;
				}
				item.clear();
				item.push_back(key);
				tuple<string, int, int> pre;
				while (pos != -1) {
					pre = q[pos];
					item.push_back(get<0>(pre));
					pos = get<2>(pre);
				}
				//    reverse(item.begin(), item.end());
				ret.push_back(item);
			}

			for (int i = 0; i < graph[key].size(); i++) {
				string nextKey = graph[key][i];
				if (visited.find(graph[key][i]) == visited.end() || visited[nextKey] == step + 1) {
					q.push_back(tuple(nextKey, step + 1, j));
					visited.insert(pair(nextKey, step + 1));
				}
			}
			j++;
		}
		return 0;
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
};