/******************************************************************************
 *  Compilation:  javac-algs4 Permutation.java
 *  Execution:    java-algs4 Permutation 3
 *  
 *  Draws a blue bullseye and textbook graphic.
 * 
 ******************************************************************************/
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
public class Permutation {
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        RandomizedQueue rq = new RandomizedQueue();
        int k = Integer.parseInt(args[0]);
        while (!StdIn.isEmpty())
            rq.enqueue(StdIn.readString());
        
        for (int i = 0; i < k; i++)
            StdOut.println(rq.dequeue());
    }
}
