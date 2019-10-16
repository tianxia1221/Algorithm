class Solution {
    class Node {
        int count; // the number of the left nodes
        int val;
        Node left;
        Node right;
        Node(int val) {
            left = null;
            right = null;
            this.val = val;
            this.count = 0;
        }
    }

    class OUTPUT {
        int count;
    }

    public List<Integer> countSmaller(int[] nums) {
        List<Integer> ret = new ArrayList<Integer>();
        if (nums.length == 0) return ret;

        Node root = new Node(nums[nums.length - 1]);
        ret.add(root.count);
        for (int i = nums.length - 2; i >= 0; i--) {
            Node newNode = new Node(nums[i]);
            OUTPUT item = new OUTPUT();
            insert(root, newNode, item);
            ret.add(item.count);
        }
        Collections.reverse(ret);
        return ret;
    }

    void insert(Node root, Node newNode, OUTPUT small_count) {

        if (newNode.val <= root.val) {
            root.count++;
            if (root.left != null)
                insert(root.left, newNode, small_count);
            else
                root.left = newNode;
        } else {
            small_count.count += root.count + 1;
            if (root.right != null) {
                insert(root.right, newNode, small_count);
            } else {
                root.right = newNode;
            }
        }
    }
}