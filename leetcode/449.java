/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder ret = new StringBuilder();
        preOrder(root, ret);
        return ret.toString();
    }

    void preOrder(TreeNode root, StringBuilder output) {
        if (null == root) return;

        output.append(itoa(root.val));
        output.append("#");

        preOrder(root.left, output);
        preOrder(root.right, output);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        StringBuilder word = new StringBuilder();
        int val;
        TreeNode p;
        TreeNode root = null;

        for (int i = 0; i < data.length(); i++) {
            if (data.charAt(i) == '#') {
                val = atoi(word.toString());
                p = new TreeNode(val);
                word.delete(0, word.length());
                if (root == null) {
                    root = p;
                    continue;
                }

                insert(root, p);
            } else
                word.append(data.charAt(i));
        }
        return root;
    }

    void insert(TreeNode root, TreeNode newNode) {
        if (root == null) return;

        if (root.val > newNode.val) {
            if (root.left != null) insert(root.left, newNode);
            else root.left = newNode;
        } else {
            if (root.right != null) insert(root.right, newNode);
            else root.right = newNode;
        }

        return;
    }

    StringBuilder itoa(int i) {
        StringBuilder ret = new StringBuilder();
        while (i > 0) {
            ret.append((char) (i % 10 + '0'));
            i = i / 10;
        }
        return ret;
    }

    int atoi(String s) {
        int ret = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            ret = ret * 10 + (int) (s.charAt(i) - '0');
        }
        return ret;
    }
}


// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));