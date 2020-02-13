class Solution {

    public boolean canFinish(int numCourses, int[][] prerequisites) {

        char[] degree = new char[numCourses];
        List<Integer> zeroList = new ArrayList<>();

        List<Integer>[] graph = new List[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList<Integer>();
        }

        constructGraph(prerequisites, graph, degree, zeroList);

        int cur;
        int to;
        List<Integer> toList;
        while (!zeroList.isEmpty()) {
            cur = zeroList.remove(zeroList.size() - 1);
            toList = graph[cur];
            for (int i = 0; i < toList.size(); i++) {
                to = toList.get(i);
                degree[to]--;
                if (degree[to] == 0) {
                    zeroList.add(to);
                }
            }
        }

        for (int i : degree) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }

    void constructGraph(int[][] pre, List<Integer>[] graph, char[] degree, List<Integer> zeroList) {
        List<Integer> arr;
        for (int i = 0; i < pre.length; i++) {
            arr = graph[pre[i][1]];
            arr.add(pre[i][0]);
            degree[pre[i][0]]++;
        }

        for (int i = 0; i < degree.length; i++) {
            if (degree[i] == 0) {
                zeroList.add(i);
            }
        }
    }

}