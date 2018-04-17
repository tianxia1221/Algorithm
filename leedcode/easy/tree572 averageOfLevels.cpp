//572. Subtree of Another Tree
//Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
//
//Example 1:
//Given tree s:
//
//3
/// \
//4   5
/// \
//1   2
//Given tree t:
//4
/// \
//1   2
//Return true, because t has the same structure and node values with a subtree of s.
//Example 2:
//Given tree s:
//
//3
/// \
//4   5
/// \
//1   2
///
//0
//Given tree t:
//4
/// \
//1   2
//Return false.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//!!!!!!!!!!!!!!!!!!!!!!!!
public boolean isSubtree(TreeNode s, TreeNode t) {
    return serialize(s).contains(serialize(t)); // Java uses a naive contains algorithm so to ensure linear time,
    // replace with KMP algorithm
}

public String serialize(TreeNode root) {
    StringBuilder res = new StringBuilder();
    serialize(root, res);
    return res.toString();
}

private void serialize(TreeNode cur, StringBuilder res) {
    if (cur == null) {res.append(",#"); return;}
    res.append("," + cur.val);
    serialize(cur.left, res);
    serialize(cur.right, res);
}
////////////////////////////////

public class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if (s == null) return false;
        if (isSame(s, t)) return true;
        return isSubtree(s.left, t) || isSubtree(s.right, t);
    }
    
    private boolean isSame(TreeNode s, TreeNode t) {
        if (s == null && t == null) return true;
        if (s == null || t == null) return false;
        
        if (s.val != t.val) return false;
        
        return isSame(s.left, t.left) && isSame(s.right, t.right);
    }
}

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t && !s) return true;
        if(!s || !t) return false;
        
        if(s->val == t->val) {
            if(isSame(s->left,t->left)&&isSame(s->right, t->right)) return true;
        }
        
        if(isSubtree(s->left, t)) return true;
        if(isSubtree(s->right,t)) return true;
        
        return false;
    }
    
    bool isSame(TreeNode* s, TreeNode* t){
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val != t->val) return false;
        if(!isSame(s->left,t->left)) return false;
        if(!isSame(s->right, t->right)) return false;
        
        return true;
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
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t && !s) return true;
        if(!s || !t) return false;
        
        if(s->val == t->val) {
            if(isSame(s->left,t->left)&&isSame(s->right, t->right)) return true;
        }
        
        if(isSubtree(s->left, t)) return true;
        if(isSubtree(s->right,t)) return true;
        
        return false;
    }
    
    bool isSame(TreeNode* s, TreeNode* t){   //@@@iteration instead of recursion
        if(!s && !t) return true;
        if(!s || !t) return false;
        queue<TreeNode *> qs;
        TreeNode *curS, *curT;
        qs.push(s);
        qs.push(t);
        while(!qs.empty()){
            curS = qs.front();
            qs.pop();
            curT = qs.front();
            qs.pop();
            if(curS->val != curT->val) return false;
            if(curS->left){
                if(!curT->left) return false;
                qs.push(curS->left);
                qs.push(curT->left);
            }
            else{
                if(curT->left) return false;
            }
            if(curS->right){
                if(!curT->right) return false;
                qs.push(curS->right);
                qs.push(curT->right);
            }
            else{
                if(curT->right) return false;
            }
        }
        
        return true;
    }
};
