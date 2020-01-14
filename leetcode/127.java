
class Solution {
    class Pair {
        String first;
        int second;

        Pair(String first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int ret = 0;
        Map<String, List<String>> graph = new HashMap<>();

        Set<String> visited = new HashSet<>();
        wordList.add(beginWord);

        for (int i = 0; i < wordList.size(); i++) {
            graph.put(wordList.get(i), new ArrayList<String>());
        }

        construct_graph(wordList, graph);

        return bfs(beginWord, endWord, graph, visited);
    }

    boolean connect(String word1, String word2) {
        int count = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1.charAt(i) != word2.charAt(i)) count++;
        }
        return count == 1;
    }

    void construct_graph(List<String> wordList, Map<String, List<String>> graph) {
        String istr;
        String jstr;
        for (int i = 0; i < wordList.size() - 1; i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                istr = wordList.get(i);
                jstr = wordList.get(j);
                if (connect(istr, jstr)) {
                    graph.get(istr).add(new String(jstr));
                    graph.get(jstr).add(new String(istr));
                }
            }
        }
    }

    int bfs(String beginWord, String endWord, Map<String, List<String>> graph, Set<String> visited) {
        int ret = 0;
        List<String> list;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(beginWord, 1));
        visited.add(beginWord);
        Pair cur;
        while (0 != q.size()) {
            cur = q.remove();
            if (cur.first.equals(endWord)) return cur.second;
            list = graph.get(cur.first);
            for (int i = 0; i < list.size(); i++) {
                if (visited.contains(list.get(i)) == false) {
                    q.add(new Pair(list.get(i), cur.second + 1));
                    visited.add(list.get(i));
                }
            }
        }
        return 0;
    }
};