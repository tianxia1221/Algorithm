class WordDictionary {
    class Node {
        Node[] child = new Node[26];
        boolean isEnd = false;
    }

    private Node root;
    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return search(word, 0, root);
    }

    boolean search(String word, int startPos, Node startNode) {
        int index = 0;
        boolean ret;
        if(startPos == word.length()) {
            if(startNode==null)  return false;
            return startNode.isEnd;
        }

        if('.' !=  word.charAt(startPos)){
            index = word.charAt(startPos) - 'a';
            if(null == startNode.child[index]){
                return false;
            }
            ret = search(word, startPos+1, startNode.child[index]);
            if(ret) return true;
        }
        else {
            for(int j=0; j<26; j++) {
                if(null == startNode.child[j]) continue;
                ret = search(word, startPos+1, startNode.child[j]);
                if(ret) return true;
            }
        }
        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */