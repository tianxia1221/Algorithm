
class Solution {
    class Pair{
        String first;
        int step;
        int index;
        Pair(String first, int step, int index){
            this.first = first;
            this.step = step;
            this.index = index;
        }
    }

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> ret = new ArrayList<>();
        Map<String, List<String>> graph = new HashMap<>();
        Map<String, Integer> visited = new HashMap<>();

        if(!wordList.contains(beginWord)) wordList.add(beginWord);

        for(int i=0; i<wordList.size(); i++) {
            graph.put(wordList.get(i), new ArrayList<String>());
        }
        construct_graph(wordList, graph);
        bfs( endWord, beginWord, graph, visited, ret);
        return ret;
    }

    void bfs(String beginWord, String endWord, Map<String, List<String>> graph, Map<String, Integer> visited, List<List<String>> ret ){
        List<String> list;
        List<Pair> q = new ArrayList<>();
        q.add(new Pair(beginWord, 1, -1));
        visited.put(beginWord, 1);
        Pair cur ;
        int j = 0 ;

        int min_step = Integer.MAX_VALUE;
        boolean isFind = false;
        int pos;
        while( j < q.size()) {
            cur = q.get(j);
            if(cur.step > min_step) break;
            if(cur.first.equals(endWord)){
                if(!isFind) {
                    min_step = cur.step;
                }
                List<String> item = new ArrayList<>();
                item.add(cur.first);
                pos = cur.index;
                while(-1 != pos) {
                    item.add(q.get(pos).first);
                    pos = q.get(pos).index;
                }
                ret.add(item);
            }

            list = graph.get(cur.first);
            int size = 0;
            if(list != null ) size = list.size();
            for(int i=0; i<size; i++) {
                if(visited.containsKey(list.get(i)) == false || visited.get(list.get(i)) ==  cur.step + 1){
                    q.add(new Pair(list.get(i), cur.step + 1, j));
                    visited.put(list.get(i), cur.step + 1);
                }
            }
            j++;
        }
        return;
    }

    boolean connect(String word1, String word2){
        int count = 0;
        for(int i=0; i<word1.length(); i++) {
            if(word1.charAt(i) != word2.charAt(i)) count++;
        }
        return count==1;
    }

    void construct_graph(List<String> wordList, Map<String, List<String>> graph) {
        String istr;
        String jstr;
        for(int i=0; i<wordList.size()-1; i++) {
            for(int j=i+1; j<wordList.size(); j++){
                istr = wordList.get(i);
                jstr = wordList.get(j);
                if(connect(istr, jstr)){
                    graph.get(istr).add(new String(jstr));
                    graph.get(jstr).add(new String(istr));
                }
            }
        }

    }
};