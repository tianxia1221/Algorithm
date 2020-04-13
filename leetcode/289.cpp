class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++) {
           for(int j=0; j<n; j++) {
                if(board[i][j] == 0 ) {
                    if(isLive(board, i, j, m, n )){
                        board[i][j] = -2;
                    }
                }
               else if(board[i][j] == 1 ) {
                    if(isDie(board, i, j, m, n )){
                        board[i][j] = -1;
                    }
                }
            }
        }

        for(int i=0; i<m; i++) {
           for(int j=0; j<n; j++) {
                if(board[i][j]== -2 ) {
                   board[i][j] = 1;
                }
               else if(board[i][j]== -1){
                   board[i][j] = 0;
               }
            }
        }

    }

    bool isLive(vector<vector<int>>& board, int x, int y, int m, int n) {
        static int dx[] = {-1, 0 , 1, -1, 1, -1, 0 , 1};
        static int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int newx, newy, count = 0;
        for(int i=0; i<8; i++){
            newx = x + dx[i];
            newy = y + dy[i];
            if(newx>=0 && newx < m && newy>=0 && newy < n) {
                if(board[newx][newy] & 1 == 1 ) count++;
                if(count > 3) return false;
            }
        }
        return count==3;
    }

    bool isDie(vector<vector<int>>& board, int x, int y, int m, int n) {
        static int dx[] = {-1, 0 , 1, -1, 1, -1, 0 , 1};
        static int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int newx, newy, count = 0;
        for(int i=0; i<8; i++){
            newx = x + dx[i];
            newy = y + dy[i];
            if(newx>=0 && newx < m && newy>=0 && newy < n) {
                if(board[newx][newy] & 1== 1) count++;
            }
        }
        return count<2 || count>3;
    }

};