/******************************************************************************
 *  Compilation:  javac-algs4 Percolation.java
 *  Execution:    java-algs4 Percolation 
 *  
 *  Draws a blue bullseye and textbook graphic.
 * 
 ******************************************************************************/
import edu.princeton.cs.algs4.WeightedQuickUnionUF;
public class Percolation {
    
    private final WeightedQuickUnionUF uf;
    private final int nGrid;
    private boolean[][] map;
    private int number;
    
    public Percolation(int nGrid) {
        if (nGrid <= 0)
            throw new IllegalArgumentException();
        this.nGrid = nGrid;
        uf = new WeightedQuickUnionUF((nGrid + 2) * (nGrid + 2));
        map = new boolean[nGrid + 2][nGrid + 2];
        map[0][0] = true;
        map[nGrid + 1][0] = true;
        int i;
        for (i = 1; i <= nGrid; i++) {
            int index1 = nGrid + 2 + i;
            int index2 = 0;
            uf.union(index1, index2);
        }
        for (i = 1; i <= nGrid; i++) {
            int index1 = nGrid * (nGrid + 2) + i;
            int index2 = (nGrid + 1) * (nGrid + 2);
            uf.union(index1, index2);
        }
        number = 0;
    }
    
    public void open(int i, int j) {
        number++;
        if (i < 1 || i > nGrid || j < 1 || j > nGrid)
            throw new IndexOutOfBoundsException();
        int index1 = i * (nGrid + 2) + j;
        int index2;
        if (map[i][j])
            return;
        map[i][j] = true;
        if (i - 1 >= 1) {
            if (map[i - 1][j]) {
                index2 = (i - 1) * (nGrid + 2) + j;
                uf.union(index1, index2);
            }
        }
        if (i + 1 <= nGrid) {
            if (map[i + 1][j]) {
                index2 = (i + 1) * (nGrid + 2) + j;
                uf.union(index1, index2);
            }
        }
        if (j - 1 >= 1) {
            if (map[i][j - 1]) {
                index2 = i * (nGrid + 2) + j - 1;
                uf.union(index1, index2);
            }
        }
        if (j + 1 <= nGrid) {
            if (map[i][j + 1]) {
                index2 = i * (nGrid + 2) + j + 1;
                uf.union(index1, index2);
            }
        }
    }
    
    public boolean isOpen(int i, int j) {
        if (i < 1 || i > nGrid || j < 1 || j > nGrid)
            throw new IndexOutOfBoundsException();
        if (map[i][j])
            return true;
        return false;
    }
    
    public boolean isFull(int i, int j) {
        if (i < 1 || i > nGrid || j < 1 || j > nGrid)
            throw new IndexOutOfBoundsException();
        if (nGrid == 1)
            return isOpen(1, 1);
        int index1 = i * (nGrid + 2) + j;
        int index2 = 0;
        if (isOpen(i, j))
            return uf.connected(index1, index2);
        else
            return false;
    }
    
    public boolean percolates() {
        if (nGrid == 1)
            return isOpen(1, 1);
        int index1 = 0;
        int index2 = (nGrid + 1) * (nGrid + 2);
        return uf.connected(index1, index2);
    }
    
    public int numberOfOpenSites() {
        return number;
    }
    
    public static void main(String[] args) {
        Percolation p = new Percolation(5);
        p.open(1, 3);
        p.open(2, 3);
        p.open(3, 2);
        p.open(2, 2);
        p.open(5, 1);
        p.open(4, 1);
        p.open(3, 1);
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++)
                System.out.print(p.map[i][j] + " ");
            System.out.print("\n");
        }
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++)
                System.out.print(p.isFull(i, j) + " ");
            System.out.print("\n");
        }
        System.out.print(p.percolates());
    }
    
}
