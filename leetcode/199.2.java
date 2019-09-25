/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        //Queue<TreeNode> q = new Queue<TreeNode>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        List<Integer> result = new ArrayList<Integer>();
        TreeNode front = null;

        if (null == root) return result;

        q.add(root);
        q.add(null);
        int pre = root.val;

        //while(!q.empty()) {
        while (0 != q.size()) {
            front = q.remove();
            if (null == front) {
                result.add(pre);
                if (0 != q.size()) q.add(null);
                continue;
            }
            pre = front.val;

            if (null != front.left) q.add(front.left);
            if (null != front.right) q.add(front.right);
        }

        return result;
    }
}