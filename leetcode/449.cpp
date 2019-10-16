/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string ret;
		preOrder(root, ret);
		return ret;
	}

	void preOrder(TreeNode* root, string &output) {
		if (!root) return;
		output += itoa(root->val);
		output += "#";

		preOrder(root->left, output);
		preOrder(root->right, output);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		string word;
		int val;
		TreeNode * p;
		TreeNode * root = NULL;

		for (int i = 0; i < data.size(); i++) {
			if (data[i] == '#') {
				val = atoi(word);
				p = new TreeNode(val);
				word = "";
				if (root == NULL) {
					root = p;
					continue;
				}

				insert(root, p);
			}
			else
				word += data[i];
		}
		return root;
	}

	void insert(TreeNode *root, TreeNode *newNode) {
		if (root == NULL) return;

		if (root->val > newNode->val) {
			if (root->left) insert(root->left, newNode);
			else root->left = newNode;
		}
		else {
			if (root->right) insert(root->right, newNode);
			else root->right = newNode;
		}

		return;
	}

	string itoa(int i) {
		string ret;
		while (i) {
			ret += i % 10 + '0';
			i = i / 10;
		}

		return string(ret.rbegin(), ret.rend());
	}

	int atoi(string &s) {
		int ret = 0;
		for (int i = 0; i < s.size(); i++) {
			ret = ret * 10 + s[i] - '0';
		}
		return ret;
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string ret;
		preOrder(root, ret);
		return ret;
	}

	void preOrder(TreeNode* root, string &output) {
		if (!root) return;
		output += itoa(root->val);
		output += "#";

		preOrder(root->left, output);
		preOrder(root->right, output);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		string word;
		int val;
		TreeNode * p;
		TreeNode * root = NULL;

		for (int i = 0; i < data.size(); i++) {
			if (data[i] == '#') {
				val = atoi(word);
				p = new TreeNode(val);
				word = "";
				if (root == NULL) {
					root = p;
					continue;
				}

				insert(root, p);
			}
			else
				word += data[i];
		}
		return root;
	}

	void insert(TreeNode *root, TreeNode *newNode) {
		if (root == NULL) return;

		if (root->val > newNode->val) {
			if (root->left) insert(root->left, newNode);
			else root->left = newNode;
		}
		else {
			if (root->right) insert(root->right, newNode);
			else root->right = newNode;
		}

		return;
	}

	string itoa(int i) {
		string ret;
		while (i) {
			ret += i % 10 + '0';
			i = i / 10;
		}
      //return string(ret.rbegin(), ret.rend());
		return ret;
	}

	int atoi(string &s) {
		int ret = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			ret = ret * 10 + s[i] - '0';
		}
		return ret;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));