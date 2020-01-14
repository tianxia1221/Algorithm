class tuple{
    int x;
    int y;
    int z;
    tuple(int x, int y, int z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

class Solution {
    public int trapRainWater(int[][] heightMap) {

        if(heightMap.length == 0) return 0;

        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};
        int ret = 0;
        int row = heightMap.length;
        int col = heightMap[0].length;
        boolean[][] mark = new boolean[row][col];

        //PriorityQueue<tuple> q = new PriorityQueue<tuple>((tuple a, tuple b) -> a.z - b.z);
        PriorityQueue<tuple> q = new PriorityQueue<tuple>(new Comparator<tuple>(){
            public int compare(tuple a, tuple b) {
                return a.z - b.z;
            }
        });

        //init priority queue
        for(int i=0; i<row; i++) {
            q.add(new tuple(i, 0, heightMap[i][0]));
            mark[i][0] = true;

            q.add(new tuple(i, col-1, heightMap[i][col-1]));
            mark[i][col-1] = true;
        }

        for(int i=1; i<col-1; i++){
            q.add(new tuple(0, i, heightMap[0][i]));
            mark[0][i] = true;

            q.add(new tuple(row-1, i, heightMap[row-1][i]));
            mark[row-1][i] = true;
        }

        tuple cur;
        int newx,newy;
        while(q.size()!=0){
            cur = q.remove();

            for(int i=0; i<4; i++) {
                newx = cur.x + dx[i];
                newy = cur.y + dy[i];
                if(newx<0 || newy<0 || newx>=row || newy>=col || mark[newx][newy]) continue;
                if(heightMap[newx][newy] < cur.z) {
                    ret += cur.z-heightMap[newx][newy];
                    heightMap[newx][newy] = cur.z;
                }

                mark[newx][newy] = true;
                q.add(new tuple(newx, newy, heightMap[newx][newy]));

            }

        }

        return ret;

    }
}
