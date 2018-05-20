/******************************************************************************
 *  Compilation:  javac-algs4 PointSET.java
 *  Execution:    java-algs4 PointSET 
 *  
 *  Draws a blue bullseye and textbook graphic.
 * 
 ******************************************************************************/
import java.util.TreeSet;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.StdDraw;

public class PointSET {
    private final TreeSet<Point2D> pointSET;
    
    public PointSET() {
        this.pointSET = new TreeSet<Point2D>();
    } // construct an empty set of points
    
    public boolean isEmpty() {
        return this.pointSET.size() == 0;
    } // is the set empty?
    
    public int size() {
        return this.pointSET.size();
    } // number of points in the set
    
    public void insert(Point2D p) {
        this.pointSET.add(p);
    } // add the point to the set (if it is not already in the set)
    
    public boolean contains(Point2D p) {
        
        return pointSET.contains(p);
    } // does the set contain point p?
    
    public void draw() {
        for (Point2D p : pointSET) {
            StdDraw.point(p.x(), p.y());
        }
    } // draw all points to standard draw
    
    public Iterable<Point2D> range(RectHV rect) {
        TreeSet<Point2D> rangeSet = new TreeSet<Point2D>();
        for (Point2D p : pointSET) {
            if (rect.contains(p)) {
                rangeSet.add(p);
            }
        }
        return rangeSet;
        
    } // all points that are inside the rectangle
    
    public Point2D nearest(Point2D p) {
        Point2D nearestPoint2D = null;
        double distance = Double.MAX_VALUE;
        
        if (this.pointSET.isEmpty()) {
            return nearestPoint2D;
        }
        
        for (Point2D pointIter : pointSET) {
            if (pointIter.distanceTo(p) < distance) {
                nearestPoint2D = pointIter;
                distance = pointIter.distanceTo(p);
            }
        }
        return nearestPoint2D;
    } // a nearest neighbor in the set to point p; null if the set is empty
    
    public static void main(String[] args) {
        
       In in = new In("kdtree/input400K.txt");
        
        StdDraw.show();
        
        // initialize the data structures with N points from standard input
        PointSET brute = new PointSET();
        // KdTree kdtree = new KdTree();
        while (!in.isEmpty()) {
            double x = in.readDouble();
            double y = in.readDouble();
            Point2D p = new Point2D(x, y);
            // kdtree.insert(p);
            brute.insert(p);
        }
        
        double x0 = 0.0, y0 = 0.0; // initial endpoint of rectangle
        double x1 = 0.0, y1 = 0.0; // current location of mouse
        boolean isDragging = false; // is the user dragging a rectangle
        
        // draw the points
        StdDraw.clear();
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setPenRadius(0.01);
        brute.draw();
        
        while (true) {
            StdDraw.show();
            
            // user starts to drag a rectangle
            if (StdDraw.mousePressed() && !isDragging) {
                x0 = StdDraw.mouseX();
                y0 = StdDraw.mouseY();
                isDragging = true;
                continue;
            }
            
            // user is dragging a rectangle
            else if (StdDraw.mousePressed() && isDragging) {
                x1 = StdDraw.mouseX();
                y1 = StdDraw.mouseY();
                continue;
            }
            
            // mouse no longer pressed
            else if (!StdDraw.mousePressed() && isDragging) {
                isDragging = false;
            }
            
            RectHV rect = new RectHV(Math.min(x0, x1), Math.min(y0, y1), Math.max(x0, x1), Math.max(y0, y1));
            // draw the points
            StdDraw.clear();
            StdDraw.setPenColor(StdDraw.BLACK);
            StdDraw.setPenRadius(0.01);
            brute.draw();
            
            // draw the rectangle
            StdDraw.setPenColor(StdDraw.BLACK);
            StdDraw.setPenRadius();
            rect.draw();
            
            // draw the range search results for brute-force data structure in
            // red
            StdDraw.setPenRadius(0.03);
            StdDraw.setPenColor(StdDraw.RED);
            for (Point2D p : brute.range(rect))
                p.draw();
            
            // draw the range search results for kd-tree in blue
            StdDraw.setPenRadius(0.02);
            StdDraw.setPenColor(StdDraw.BLUE);
            // for (Point2D p : kdtree.range(rect))
            // p.draw();
            
            StdDraw.show();
        }
    } // unit testing of the methods (optional)
}