class Solution {

    class Node {
        int label;
        List<Integer> to;

        Node(int label) {
            this.label = label;
            to = new ArrayList();
        }
    }

    enum STATE {
        WAIT,
        RUNNING,
        OVER
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Node> graph = new ArrayList<>();
        STATE[] state = new STATE[numCourses];
        List<Integer> markOneTreeIdx = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            graph.add(new Node(i));
            state[i] = STATE.WAIT;
        }

        for (int i = 0; i < prerequisites.length; i++) {
            graph.get(prerequisites[i][1]).to.add(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (true == bfsHasCircle(graph, i, state, markOneTreeIdx)) {
                return false;
            }

            for (int j = 0; j < markOneTreeIdx.size(); j++)
                if (state[markOneTreeIdx.get(j)] == STATE.RUNNING) state[markOneTreeIdx.get(j)] = STATE.OVER;

        }

        return true;
    }

    private boolean bfsHasCircle(List<Node> graph, int index, STATE[] state, List<Integer> markOneTreeIdx) {
        Node curNode;
        int to;

        if (state[index] == STATE.OVER) return false;

        Queue<Integer> q = new LinkedList<>();
        q.add(index);
        state[index] = STATE.RUNNING;

        markOneTreeIdx.clear();

        while (q.size() > 0) {

            curNode = graph.get(q.remove());
            state[curNode.label] = STATE.RUNNING;

            markOneTreeIdx.add(curNode.label);
            System.out.println("----");
            System.out.println(curNode.label);

            for (int i = 0; i < curNode.to.size(); i++) {
                to = curNode.to.get(i);
                System.out.println(to + "  " + state[to]);

                if (state[to] == STATE.RUNNING) return true;
                if (state[to] == STATE.OVER) continue;

                q.add(to);
                state[to] = STATE.RUNNING;
            }
            // state[curNode.label] = STATE.OVER;
        }
        return false;
    }

}

