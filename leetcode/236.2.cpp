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
		TreeNode *l, *r;
		if (NULL == root) return NULL;

		if (root == p) return root;
		if (root == q) return root;

		l = lowestCommonAncestor(root->left, p, q);

		r = lowestCommonAncestor(root->right, p, q);


		return !l ? r : !r ? l : root;

	}

};