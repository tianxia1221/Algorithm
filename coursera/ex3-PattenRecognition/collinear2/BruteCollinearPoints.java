/******************************************************************************
 *  Compilation:  javac-algs4 BruteCollinearPoints.java
 *  Execution:    java-algs4 BruteCollinearPoints 
 *  
 *  Draws a blue bullseye and textbook graphic.
 * 
 ******************************************************************************/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

/**
 * @author evasean www.cnblogs.com/evasean/
 */
public class BruteCollinearPoints {
    private int segNum;
    private final ArrayList<LineSegment> segmentList = new ArrayList<LineSegment>();
    
    public BruteCollinearPoints(Point[] inpoints) {
        Point[] points;
        if (inpoints == null)
            throw new IllegalArgumentException("Constructor argument Point[] is null!");
        // finds all line segments containing 4 points
        for (int i = 0; i < inpoints.length; i++) {
            if (inpoints[i] == null)
                throw new IllegalArgumentException("there is null in constructor argument");
        }
        points = new Point[inpoints.length];
        for (int i = 0; i < inpoints.length; i++) {
            points[i] = inpoints[i];
        }
        Arrays.sort(points); // 对本对象的私有数组进行排序
        for (int i = 0; i < points.length - 1; i++) {
            if (points[i].compareTo(points[i + 1]) == 0) // 与前一个元素相等
                throw new IllegalArgumentException("there exists repeated points!");
        }
        // 作业提交时提示随机穿插顺序调用numberOfSegments()和segment()方法返回结果要求稳定
        // 那么构造函数中就要把LineSegment找好
        findLineSegment(points);
    }
    
    private void findLineSegment(Point[] ps) {
        int pNum = ps.length;
        for (int i = 0; i < pNum - 3; i++) { // i不需要遍历最后三个节点，因为至少四个节点才能组成LineSegment
            // 每个comparator需要占据额外空间，总共需要n-4个Comparator<Point>的额外空间
            Comparator<Point> comparator = ps[i].slopeOrder();
            for (int j = i + 1; j < pNum - 2; j++) {
                if (ps[j].compareTo(ps[i]) == 0)
                    continue; // 相同point直接跳过
                for (int x = j + 1; x < pNum - 1; x++) {
                    if (ps[x].compareTo(ps[i]) == 0)
                        continue;
                    if (ps[x].compareTo(ps[j]) == 0)
                        continue;
                    if (comparator.compare(ps[j], ps[x]) == 0) { // point[j]和point[l]相对于point[i]的斜率相等
                        for (int m = x + 1; m < pNum; m++) {
                            if (ps[m].compareTo(ps[i]) == 0)
                                continue;
                            if (ps[m].compareTo(ps[j]) == 0)
                                continue;
                            if (ps[m].compareTo(ps[x]) == 0)
                                continue;
                            if (comparator.compare(ps[x], ps[m]) == 0) {
                                // point[l]和point[m]相对于point[i]的斜率相等时，i、j、l、m
                                // 四点可以组成一个linesegment
                                // 每个LineSegment需要占据一份额外空间
                                LineSegment seg = new LineSegment(ps[i], ps[m]);
                                segmentList.add(seg);
                            }
                        }
                    }
                }
            }
        }
        segNum = segmentList.size();
        
    }
    
    public int numberOfSegments() {
        // the number of line segments
        return segNum;
    }
    
    public LineSegment[] segments() {
        // the line segments
        // 作业提交时，提示要求多次调用segments()方法返回的应该是不同的对象
        LineSegment[] segments = new LineSegment[segNum];
        int i = 0;
        for (LineSegment seg : segmentList) {
            segments[i++] = seg;
        }
        return segments;
    }
    
    public static void main(String[] args) {
        // read the n points from a file
        // In in = new In(args[0]);
        In in = new In("collinear/input8.txt"); // 本地测试使用
        int n = in.readInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = in.readInt();
            int y = in.readInt();
            points[i] = new Point(x, y);
        }
        
        // draw the points
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        StdDraw.setPenColor(StdDraw.RED);
        StdDraw.setPenRadius(0.01);
        for (Point p : points) {
            p.draw();
        }
        StdDraw.show();
        
        // print and draw the line segments
        BruteCollinearPoints collinear = new BruteCollinearPoints(points);
        for (LineSegment segment : collinear.segments()) {
            StdOut.println(segment);
            segment.draw();
        }
        StdDraw.show();
    }
}