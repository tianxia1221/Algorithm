
class Trie {
    class Node {
        Node[] child = new Node[26];
        boolean isEnd = false;
    }

    private Node root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        Node cur = root;
        int index = 0;
        for(int i=0; i<word.length(); i++) {
            index = word.charAt(i) - 'a';
            if(null == cur.child[index]) {
                (cur.child)[index] = new Node();
            }
            cur = cur.child[index];
        }

        cur.isEnd = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Node cur = root;
        int index = 0;
        for(int i=0; i<word.length(); i++) {
            index = word.charAt(i) - 'a';
            if(null == cur.child[index]){
                return false;
            }
            cur = cur.child[index];
        }
        return cur.isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Node cur = root;
        int index = 0;
        for(int i=0; i<prefix.length(); i++) {
            index = prefix.charAt(i) - 'a';
            if(null == cur.child[index]){
                return false;
            }
            cur = cur.child[index];
        }
        return true;
    }
}
