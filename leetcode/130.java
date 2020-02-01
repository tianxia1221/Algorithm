class Pos {
    int x;
    int y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public void solve(char[][] board) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        int newx;
        int newy;

        int row = board.length;
        if (row < 3) return;

        int col = board[0].length;
        if (col < 3) return;

        List<Pos> q = new ArrayList<>();

        int lastCol = col - 1;
        int lastRow = row - 1;
        Pos pos;
        // 1. init queue
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                q.add(new Pos(i, 0));
                board[i][0] = 'a';
            }

            if (board[i][lastCol] == 'O') {
                q.add(new Pos(i, lastCol));
                board[i][lastCol] = 'a';
            }
        }

        for (int i = 1; i < lastCol; i++) {
            if (board[0][i] == 'O') {
                q.add(new Pos(0, i));
                board[0][i] = 'a';
            }

            if (board[lastRow][i] == 'O') {
                q.add(new Pos(lastRow, i));
                board[lastRow][i] = 'a';
            }
        }

        // 2. bfs
        while (q.size() != 0) {
            pos = q.get(q.size() - 1);
            q.remove(q.size() - 1);

            for (int i = 0; i < 4; i++) {
                newx = pos.x + dx[i];
                newy = pos.y + dy[i];
                if (newx >= 0 && newx < row && newy >= 0 && newy < col && board[newx][newy] == 'O') {
                    q.add(new Pos(newx, newy));
                    board[newx][newy] = 'a';
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'a') {
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }
}