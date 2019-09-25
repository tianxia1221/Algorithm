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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        ArrayList<TreeNode> pPath = new ArrayList<>();
        ArrayList<TreeNode> qPath = new ArrayList<>();

        getPath(root, p, pPath);
        getPath(root, q, qPath);

        return getLowestCommonAncestor(pPath, qPath);
    }

    boolean getPath(TreeNode root, TreeNode target, ArrayList<TreeNode> path) {
        boolean isFound = false;
        if (root == null) return isFound;

        path.add(root);

        if (root == target) {
            return true;
        }

        if (root.left != null) {
            isFound = getPath(root.left, target, path);
            if (isFound) return true;
        }
        if (root.right != null) {
            isFound = getPath(root.right, target, path);
            if (isFound) return true;
        }
        path.remove(path.size() - 1);

        return false;
    }

    TreeNode getLowestCommonAncestor(ArrayList<TreeNode> p, ArrayList<TreeNode> q) {
        TreeNode result = null;
        int minLenght = Math.min(p.size(), q.size());
        for (int i = 0; i < minLenght; i++) {
            if (p.get(i) != q.get(i)) break;
            result = p.get(i);
        }
        return result;
    }
}