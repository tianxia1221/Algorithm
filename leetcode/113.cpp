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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> path;
		pathSum(root, sum, result, path);
		return result;
	}

	void pathSum(TreeNode* root, int sum, vector<vector<int>> &result, vector<int> &path) {
		if (!root) return;

		sum -= root->val;
		path.push_back(root->val);


		if (!root->left && !root->right) {

			if (sum == 0) result.push_back(path);

			path.pop_back();
			return;
		}

		if (root->left) pathSum(root->left, sum, result, path);
		if (root->right) pathSum(root->right, sum, result, path);

		path.pop_back();

	}
};