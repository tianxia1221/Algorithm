//Runtime: 2 ms, faster than 99.66% of Java online submissions for Course Schedule.
//Memory Usage: 52.2 MB, less than 27.69% of Java online submissions for Course Schedule.
class Solution {
    enum State {
        Waiting,
        Running,
        Over,
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {

        State[] mark = new State[numCourses];

        ArrayList<ArrayList<Integer>> graph = new ArrayList<>(numCourses);
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<Integer>());
            mark[i] = State.Waiting;
        }

        constructGraph(prerequisites, graph);

        for (int i = 0; i < numCourses; i++) {
            if (mark[i] == State.Over) continue;
            if (dfsHasCycle(graph, mark, i)) return false;
        }

        return true;
    }

    void constructGraph(int[][] pre, ArrayList<ArrayList<Integer>> graph) {
        int n = graph.size();
        ArrayList<Integer> arr;
        for (int i = 0; i < pre.length; i++) {
            arr = graph.get(pre[i][1]);
            arr.add(pre[i][0]);
        }
    }

    boolean dfsHasCycle(ArrayList<ArrayList<Integer>> graph, State[] mark, int cur) {
        boolean ret;
        int to;
        mark[cur] = State.Running;
        ArrayList<Integer> arr = graph.get(cur);
        for (int i = 0; i < arr.size(); i++) {
            to = arr.get(i);
            if (mark[to] == State.Running) return true;
            if (mark[to] == State.Waiting) {
                ret = dfsHasCycle(graph, mark, to);
                if (ret) return true;
            }
        }
        mark[cur] = State.Over;
        return false;
    }
}

//Runtime: 2 ms, faster than 99.66% of Java online submissions for Course Schedule.
//Memory Usage: 51.9 MB, less than 27.69% of Java online submissions for Course Schedule.
class Solution {
    enum State {
        Waiting,
        Running,
        Over,
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {

        State[] mark = new State[numCourses];

        List<Integer>[] graph = new List[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList<Integer>();
            mark[i] = State.Waiting;
        }

        constructGraph(prerequisites, graph);

        for (int i = 0; i < numCourses; i++) {
            if (mark[i] == State.Over) continue;
            if (dfsHasCycle(graph, mark, i)) return false;
        }

        return true;
    }

    void constructGraph(int[][] pre, List<Integer>[] graph) {
        int n = graph.length;
        List<Integer> arr;
        for (int i = 0; i < pre.length; i++) {
            arr = graph[pre[i][1]];
            arr.add(pre[i][0]);
        }
    }

    boolean dfsHasCycle(List<Integer>[] graph, State[] mark, int cur) {
        boolean ret;
        int to;
        mark[cur] = State.Running;
        List<Integer> arr = graph[cur];
        for (int i = 0; i < arr.size(); i++) {
            to = arr.get(i);
            if (mark[to] == State.Running) return true;
            if (mark[to] == State.Waiting) {
                ret = dfsHasCycle(graph, mark, to);
                if (ret) return true;
            }
        }
        mark[cur] = State.Over;
        return false;
    }
}

//Runtime: 2 ms, faster than 99.66% of Java online submissions for Course Schedule.
//Memory Usage: 47.3 MB, less than 44.62% of Java online submissions for Course Schedule.
class Solution {

    public boolean canFinish(int numCourses, int[][] prerequisites) {

        char[] mark = new char[numCourses];

        List<Integer>[] graph = new List[numCourses];
        for(int i=0; i<numCourses; i++){
            graph[i] = new ArrayList<Integer>();
        }

        constructGraph(prerequisites, graph);

        for(int i=0; i<numCourses; i++) {
            if(mark[i] == 2) continue;
            if( dfsHasCycle(graph, mark, i)) return false;
        }

        return true;
    }

    void constructGraph(int[][] pre, List<Integer>[] graph) {
        List<Integer> arr;
        for(int i = 0; i < pre.length; i++){
            arr = graph[pre[i][1]];
            arr.add(pre[i][0]);
        }
    }

    boolean dfsHasCycle(List<Integer>[] graph, char[] mark, int cur) {
        int to;
        mark[cur] = 1; //  0： waiting 1： running 2：over
        List<Integer> arr = graph[cur];
        for(int i = 0; i<arr.size(); i++) {
            to = arr.get(i);
            if(mark[to] == 1) return true;
            if(mark[to] == 0) {
                if(dfsHasCycle(graph, mark, to)) return true;
            }
        }
        mark[cur] = 2; //bfs end
        return false;
    }
}