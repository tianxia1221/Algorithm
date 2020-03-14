class DisjoinSet{
    private:
        vector<int> ids;
        vector<int> size;
        int count;
    public:
        DisjoinSet(int n) {
            for(int i=0; i<n; i++) {
                ids.push_back(i);
                size.push_back(1);
                count = n;
            }
        }

        void union(int i, int j){

            int pi = find(i);
            int pj = find(j);

            if(pi == pj) return;

            if(size[pi] < size[pj]) {
                ids[pi] = pj;
                size[pj] += size[pi];

            }
            else {
                ids[pj] = pi;
                size[pi] += size[pj];
            }
            count--;

        }

        int find(int i) {
            while(i != ids[i]) {
                ids[i] = ids[ids[i]];
                i = ids[i];
            }
            return i;
        }

        int getCount() {
            return count;
        }

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        DisjoinSet ds(M.size());
        for(int i=1; i<M.size(); i++) {
            for(int j=0; j<i; j++) {
                if(M[i][j]) ds.union(i,j);
            }
        }
        return ds.getCount();
    }
};