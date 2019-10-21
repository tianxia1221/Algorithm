

class WordDictionary {
	struct Node {
		Node * child[26];
		bool isEnd;
		Node() {
			for (int i = 0; i < 26; i++) child[i] = NULL;
			isEnd = false;
		}
	};
	Node root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node * cur = &root;
		int index = 0;
		for (int i = 0; i < word.size(); i++) {
			index = word[i] - 'a';
			if (NULL == cur->child[index]) {
				cur->child[index] = new Node();
			}
			cur = cur->child[index];
		}

		cur->isEnd = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(word, 0, &root);
	}

	bool search(string &word, int startPos, Node* startNode) {
		int index = 0;
		bool ret;
		if (startPos == word.size()) {
			if (startNode == NULL)  return false;
			return startNode->isEnd;
		}

		if ('.' != word[startPos]) {
			index = word[startPos] - 'a';
			if (NULL == startNode->child[index]) {
				return false;
			}
			ret = search(word, startPos + 1, startNode->child[index]);
			if (ret) return true;
		}
		else {
			for (int j = 0; j < 26; j++) {
				if (NULL == startNode->child[j]) continue;
				ret = search(word, startPos + 1, startNode->child[j]);
				if (ret) return true;
			}
		}

		return false;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */