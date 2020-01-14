class Solution {
    public:
    int findCircleNum(vector<vector<int>>& M) {
        int mark[M.size()];
        set<int> ret;
        for (int i = 0; i < M.size(); i++) {
            mark[i] = i;
        }
        for (int i = 1; i < M.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 1) {
                    int temp = mark[j];
                    for (int x = 0; x < M.size(); x++) {
                        if (mark[x] == temp) {
                            mark[x] = mark[i];
                        }
                    }
                    mark[j] = mark[i];
                }
            }
        }

        for (auto i : mark) ret.insert(i);

        return ret.size();

    }
};