//637. Average of Levels in Binary Tree
//Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
//
//Example 1:
//Input:
//3
/// \
//9  20
///  \
//15   7
//Output: [3, 14.5, 11]
//Explanation:
//The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
//Note:
//The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        TreeNode* cur;
        double sum = 0;
        
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            sum = 0;
            for(int i = 0; i<size; i++){
                cur = q.front();
                q.pop();
                sum += cur->val;
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
            }
            
            ans.push_back(sum/size);
        }
        
        return ans;
    }
};

