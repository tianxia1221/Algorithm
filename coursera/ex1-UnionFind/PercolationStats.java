/******************************************************************************
 *  Compilation:  javac-algs4 PercolationStats.java
 *  Execution:    java-algs4 PercolationStats 100 100
 *  
 *  Draws a blue bullseye and textbook graphic.
 * 
 ******************************************************************************/
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
public class PercolationStats {
    private final double[] count;
    private final int time;
    public PercolationStats(int nGrid, int time) {
        if (nGrid <= 0 || time <= 0)
            throw new IllegalArgumentException();
        count = new double[time];
        this.time = time;
        for (int k = 0; k < time; k++) {
            Percolation p = new Percolation(nGrid);
            while (!p.percolates()) {
                int i = (int) ((StdRandom.uniform() * nGrid) + 1);
                int j = (int) ((StdRandom.uniform() * nGrid) + 1);
                if (!p.isOpen(i, j)) {
                    p.open(i, j);
                    count[k] = count[k] + 1;
                }
            }
        }
        
        for (int k = 0; k < time; k++) {
            count[k] = count[k] / (nGrid * nGrid);
        }
        
    }
    
    public double mean() {
        return StdStats.mean(count);
    }
    
    public double stddev() {
        return StdStats.stddevp(count);
    }
    
    public double confidenceLo() {
        double u = mean();
        double stddev = stddev();
        double lo = u - (1.96 * stddev / Math.sqrt(time));
        return lo;
    }
    
    public double confidenceHi() {
        double u = mean();
        double stddev = stddev();
        double hi = u + (1.96 * stddev / Math.sqrt(time));
        return hi;
    }
    
    public static void main(String[] args) {
        int nGrid = Integer.parseInt(args[0]);
        int time = Integer.parseInt(args[1]);
        PercolationStats p = new PercolationStats(nGrid, time);
        System.out.print("mean:\t\t\t\t\t");
        System.out.print("= " + p.mean() + "\n");
        System.out.print("stddev:\t\t\t\t\t");
        System.out.print("= " + p.stddev() + "\n");
        System.out.print("95% confidence interval\t\t\t");
        System.out.print("= " + p.confidenceLo() + ",");
        System.out.print(p.confidenceHi() + "\n");
    }
}
