

```c++

class Solution {
const int inf=INT_MAX/2;
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        sr.push_back({target[0],target[1],target[0],target[1],0});
        sr.push_back({start[0],start[1],start[0],start[1],0});
        int n=sr.size();
        vector<int> d(n,inf);
        d[n-1]=0;
        vector<bool> vis(n,false);

        int from=n-1, minlen=INT_MAX,to=-1;

        while(true)
        {
            vis[from]=true;
            int x0=sr[from][2];
            int y0=sr[from][3];
            for(int i=0; i<n-1; i++)
            {
                if(vis[i]) continue;
                int x1=sr[i][0];
                int y1=sr[i][1];
                int x2=sr[i][2];
                int y2=sr[i][3];
                int value=sr[i][4];
                int dis1=abs(x1-x0)+abs(y1-y0)+value; //use specail edge
                int dis2=abs(x2-x0)+abs(y2-y0);  //哈夫曼距离
                d[i]=min(d[i],min(dis1,dis2)+d[from]);
                if(d[i]<minlen)
                {
                    minlen=d[i];
                    to=i;
                }
            }
            if(to==n-2) return d[n-2];
            from=to;
            minlen=INT_MAX;
            to=-1;
        }
        return 126;
    }
};

```
