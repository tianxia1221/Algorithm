/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> pPath;
		vector<TreeNode*> qPath;

		getPath(root, p, pPath);
		getPath(root, q, qPath);

		return getLowestCommonAncestor(pPath, qPath);

	}

	bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path) {
		bool isFound = false;
		if (!root) return isFound;

		path.push_back(root);

		if (root == target) {
			cout << path.size() << endl;
			return true;
		}


		if (root->left) {
			isFound = getPath(root->left, target, path);
			if (isFound) return true;
		}
		if (root->right) {
			isFound = getPath(root->right, target, path);
			if (isFound) return true;
		}
		path.pop_back();

		return false;
	}

	TreeNode* getLowestCommonAncestor(vector<TreeNode*> &p, vector<TreeNode*> &q) {
		TreeNode* result = NULL;
		int minLenght = min(p.size(), q.size());
		for (int i = 0; i < minLenght; i++) {
			if (p[i] != q[i]) break;
			result = p[i];
		}
		return result;
	}
};