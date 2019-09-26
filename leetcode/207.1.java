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
        for (int i = 0; i < numCourses; i++) {
            graph.add(new Node(i));
            state[i] = STATE.WAIT;
        }

        for (int i = 0; i < prerequisites.length; i++) {
            graph.get(prerequisites[i][1]).to.add(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {

            if (true == hasCircle(graph, i, state)) {
                return false;
            }
        }

        return true;
    }


    private boolean hasCircle(List<Node> graph, int index, STATE[] state) {
        state[index] = STATE.RUNNING;
        List<Integer> to = graph.get(index).to;

        for (Integer i : to) {
            if (state[i] == STATE.RUNNING) {
                return true;
            }
            if (hasCircle(graph, i, state)) return true;

        }
        state[index] = STATE.OVER;
        return false;
    }

}

