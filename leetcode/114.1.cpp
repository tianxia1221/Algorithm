class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode* first = NULL;
		TreeNode* last = NULL;
		flatten(root, &first, &last);
		return;
	}

private:
	void flatten(TreeNode* root, TreeNode** first, TreeNode** last) {
		if (NULL == root) return;
		TreeNode* lFirst = NULL, *lLast = NULL;
		TreeNode* rFirst = NULL, *rLast = NULL;
		TreeNode* newLast = root;
		TreeNode* orgRight = root->right;

		*first = root;
		if (!root->left && !root->right) {
			*last = root;
			return;
		}

		if (root->left) {
			flatten(root->left, &lFirst, &lLast);
			root->left = NULL;
			root->right = lFirst;
			newLast = lLast;
			*last = lLast;
		}

		if (orgRight) {
			flatten(orgRight, &rFirst, &rLast);
			newLast->right = rFirst;
			*last = rLast;
		}
	}
};