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
    void flatten(TreeNode* root) {
        TreeNode* last = NULL;
        flatten(root, &last);
        return;
    }

private:
    void flatten(TreeNode* root, TreeNode** last) {
        if(NULL == root) return;
        TreeNode* lLast = NULL;
        TreeNode* rLast = NULL;
        TreeNode* newLast = root;
        TreeNode* right = root->right;
        TreeNode* left = root->left;

        if(!root->left && !root->right){
            *last = root;
            return;
        }

        if(root->left) {
            flatten(root->left, &lLast);
            root->left = NULL;
            root->right = left;
            newLast = lLast;
            *last = lLast;
        }

        if(right) {
            flatten(right, &rLast);
            newLast->right = right;
            *last = rLast;
        }
    }
};