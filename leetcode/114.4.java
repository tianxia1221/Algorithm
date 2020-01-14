class Solution {
    public void flatten(TreeNode root) {
        TreeNode dummy = new TreeNode(0);
        flattenSub(root, dummy);
    }

    public TreeNode flattenSub(TreeNode root, TreeNode pre) {

        if (root == null) return pre;

        //  TreeNode left = root.left ;
        TreeNode right = root.right;

        pre.left = null;
        pre.right = root;
        pre = root;

        TreeNode result = pre;
        if (root.left != null) result = flattenSub(root.left, pre);

        if (right != null) result = flattenSub(right, result);

        return result;
    }
}