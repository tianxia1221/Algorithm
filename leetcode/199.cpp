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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		TreeNode* front;
		if (!root) return result;

		int pre = root->val;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		while (!q.empty()) {
			front = q.front();
			q.pop();
			cout << front << endl;
			if (!front) {
				result.push_back(pre);
				if (!q.empty())q.push(NULL);
				continue;
			}

			pre = front->val;

			if (front->left) q.push(front->left);
			if (front->right) q.push(front->right);
		}

		return result;
	}
};