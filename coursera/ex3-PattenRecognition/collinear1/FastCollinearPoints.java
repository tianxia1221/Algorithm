/******************************************************************************
 *  Compilation:  javac-algs4 FastCollinearPoints.java
 *  Execution:    java-algs4 FastCollinearPoints 
 *  
 *  Draws a blue bullseye and textbook graphic.
 * 
 ******************************************************************************/
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Collections;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;


/**
 * A fst solution of finding colinear points in a set of points.
 *
 * @author ISchwarz
 */
public class FastCollinearPoints {
    
    private final HashMap<Double, List<Point>> foundSegments = new HashMap<>();
    private final List<LineSegment> segments = new ArrayList<>();
    
    
    public FastCollinearPoints(Point[] points) {
        checkDuplicatedEntries(points);
        Point[] pointsCopy = Arrays.copyOf(points, points.length);
//        Arrays.sort(pointsCopy);
        
        for (Point startPoint : points) {
            Arrays.sort(pointsCopy, startPoint.slopeOrder());
            
            List<Point> slopePoints = new ArrayList<>();
            double slope = 0;
            double previousSlope = Double.NEGATIVE_INFINITY;
            
            for (int i = 1; i < pointsCopy.length; i++) {
                slope = startPoint.slopeTo(pointsCopy[i]);
                if (0 == Double.compare(slope, previousSlope)) {
                    slopePoints.add(pointsCopy[i]);
                } 
                else {
                    if (slopePoints.size() >= 3) {
                        slopePoints.add(startPoint);
                        addSegmentIfNew(slopePoints, previousSlope);
                    }
                    slopePoints.clear();
                    slopePoints.add(pointsCopy[i]);
                }
                previousSlope = slope;
            }
            
            if (slopePoints.size() >= 3) {
                slopePoints.add(startPoint);
                addSegmentIfNew(slopePoints, slope);
            }
        }
    }
    
    private void addSegmentIfNew(List<Point> slopePoints, double slope) {
        List<Point> endPoints = foundSegments.get(slope);
        Collections.sort(slopePoints);
        
        Point startPoint = slopePoints.get(0);
        Point endPoint = slopePoints.get(slopePoints.size() - 1);
        
        if (endPoints == null) {
            endPoints = new ArrayList<>();
            endPoints.add(endPoint);
            foundSegments.put(slope, endPoints);
            segments.add(new LineSegment(startPoint, endPoint));
        } 
        else {
            for (Point currentEndPoint : endPoints) {
                if (currentEndPoint.compareTo(endPoint) == 0) {
                    return;
                }
            }
            endPoints.add(endPoint);
            segments.add(new LineSegment(startPoint, endPoint));
        }
    }
    
    
    private void checkDuplicatedEntries(Point[] points) {
        for (int i = 0; i < points.length - 1; i++) {
            for (int j = i + 1; j < points.length; j++) {
                if (points[i].compareTo(points[j]) == 0) {
                    throw new IllegalArgumentException("Duplicated entries in given points.");
                }
            }
        }
    }
    
    public int numberOfSegments() {
        return segments.size();
    }
    
    public LineSegment[] segments() {
        return segments.toArray(new LineSegment[segments.size()]);
    }
    
    public static void main(String[] args)
    {
        // read the n points from a file
       // In in = new In(args[0]);
        In in = new In("collinear/input10000.txt"); //本地测试使用
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
        StdDraw.setPenRadius(0.001);
        for (Point p : points) { 
            p.draw(); 
        }
        StdDraw.show();
        
        // print and draw the line segments
        FastCollinearPoints collinear = new FastCollinearPoints(points);
        for (LineSegment segment : collinear.segments()) {
            StdOut.println(segment);
            segment.draw();
        }
        StdDraw.show();
    }


}