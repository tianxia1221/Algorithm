class Solution {

    class Node {
        int label;
        List<Integer> to;

        Node(int label) {
            this.label = label;
            to = new ArrayList();
        }
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Node> graph = new ArrayList<>();
        int[] degree = new int[numCourses];
        Node cur;
        int to;
        
        for (int i = 0; i < numCourses; i++) {
            graph.add(new Node(i));
        }

        for (int i = 0; i < prerequisites.length; i++) {
            graph.get(prerequisites[i][1]).to.add(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.add(i);
            }
        }

        while (q.size() > 0) {
            cur = graph.get(q.remove());
            for(int i=0; i<cur.to.size(); i++){
                to = cur.to.get(i);
                degree[to]--;
                if(degree[to] == 0) q.add(to);
            }
        }
        
		for (int i : degree) {
			if (0 != i) return false;
		}
        return true;
    }
}

