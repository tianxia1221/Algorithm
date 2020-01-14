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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> item = new ArrayList<>();
        pathSumSub(root, sum, result, item);
        return result;
    }

    void pathSumSub(TreeNode root, int sum, List<List<Integer>> result, List<Integer> item) {
        if (null == root) return;
        sum -= root.val;
        item.add(root.val);
        if (root.left == null && root.right == null) {
            if (sum == 0) {
                result.add(new ArrayList<Integer>(item));
            }
            item.remove(item.size() - 1);
            return;

        }

        if (root.left != null) pathSumSub(root.left, sum, result, item);
        if (root.right != null) pathSumSub(root.right, sum, result, item);
        item.remove(item.size() - 1);
    }
}