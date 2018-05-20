/******************************************************************************
 *  Compilation:  javac-algs4 KdTree.java
 *  Execution:    java-algs4 KdTree 
 *  
 *  Draws a blue bullseye and textbook graphic.
 * 
 ******************************************************************************/
import java.util.TreeSet;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.StdDraw;

public class KdTree {
    private static final RectHV CONTAINER = new RectHV(0, 0, 1, 1);
    private KdNode rootNode;
    private int size;
    // create struct
    private static class KdNode {
        private KdNode leftNode;
        private KdNode rightNode;
        private final boolean isVertical;
        private final double x;
        private final double y;
        
        public KdNode(final double x, final double y, final KdNode leftNode, final KdNode rightNode,
                      final boolean isVertical) {
            this.x = x;
            this.y = y;
            this.leftNode = leftNode;
            this.rightNode = rightNode;
            this.isVertical = isVertical;
        }
    }
    
    public KdTree() {
        this.size = 0;
        this.rootNode = null;
    } // construct an empty set of points
    
    public boolean isEmpty() {
        return this.size == 0;
    } // is the set empty?
    
    public int size() {
        return this.size;
    } // number of points in the set
    
    public void insert(final Point2D p) {
        this.rootNode = insert(this.rootNode, p, true);
    } // add the point to the set (if it is not already in the set)
    
    private KdNode insert(final KdNode node, final Point2D p, final boolean isVertical) {
        // if new node, create it
        if (node == null) {
            size++;
            return new KdNode(p.x(), p.y(), null, null, isVertical);
        }
        
        // if already in, return it
        if (node.x == p.x() && node.y == p.y()) {
            return node;
        }
        
        // insert it where corresponds (left - right recursive call)
        if (node.isVertical && p.x() < node.x || !node.isVertical && p.y() < node.y) {
            node.leftNode = insert(node.leftNode, p, !node.isVertical);
        } 
        else {
            node.rightNode = insert(node.rightNode, p, !node.isVertical);
        }
        return node;
    }
    
    public boolean contains(Point2D p) {
        return contains(rootNode, p.x(), p.y());
    }
    
    private boolean contains(KdNode node, double x, double y) {
        if (node == null) {
            return false;
        }
        
        if (node.x == x && node.y == y) {
            return true;
        }
        
        if (node.isVertical && x < node.x || !node.isVertical && y < node.y) {
            return contains(node.leftNode, x, y);
        } 
        else {
            return contains(node.rightNode, x, y);
        }
    } // does the set contain point p?
    
    public void draw() {
        StdDraw.setScale(0, 1);
        
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setPenRadius();
        CONTAINER.draw();
        
        draw(rootNode, CONTAINER);
    }
    
    private void draw(final KdNode node, final RectHV rect) {
        if (node == null) {
            return;
        }
        
        // draw the point
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setPenRadius(0.01);
        new Point2D(node.x, node.y).draw();
        
        // get the min and max points of division line
        Point2D min, max;
        if (node.isVertical) {
            StdDraw.setPenColor(StdDraw.RED);
            min = new Point2D(node.x, rect.ymin());
            max = new Point2D(node.x, rect.ymax());
        } 
        else {
            StdDraw.setPenColor(StdDraw.BLUE);
            min = new Point2D(rect.xmin(), node.y);
            max = new Point2D(rect.xmax(), node.y);
        }
        
        // draw that division line
        StdDraw.setPenRadius();
        min.drawTo(max);
        
        // recursively draw children
        draw(node.leftNode, leftRect(rect, node));
        draw(node.rightNode, rightRect(rect, node));
    }
    
    private RectHV leftRect(final RectHV rect, final KdNode node) {
        if (node.isVertical) {
            return new RectHV(rect.xmin(), rect.ymin(), node.x, rect.ymax());
        } 
        else {
            return new RectHV(rect.xmin(), rect.ymin(), rect.xmax(), node.y);
        }
    }
    
    private RectHV rightRect(final RectHV rect, final KdNode node) {
        if (node.isVertical) {
            return new RectHV(node.x, rect.ymin(), rect.xmax(), rect.ymax());
        } 
        else {
            return new RectHV(rect.xmin(), node.y, rect.xmax(), rect.ymax());
        }
    }
    
    // all points in the set that are inside the rectangle
    public Iterable<Point2D> range(final RectHV rect) {
        final TreeSet<Point2D> rangeSet = new TreeSet<Point2D>();
        range(rootNode, CONTAINER, rect, rangeSet);
        
        return rangeSet;
    }
    
    private void range(final KdNode node, final RectHV nrect, final RectHV rect, final TreeSet<Point2D> rangeSet) {
        if (node == null)
            return;
        
        if (rect.intersects(nrect)) {
            final Point2D p = new Point2D(node.x, node.y);
            if (rect.contains(p))
                rangeSet.add(p);
            range(node.leftNode, leftRect(nrect, node), rect, rangeSet);
            range(node.rightNode, rightRect(nrect, node), rect, rangeSet);
        }
    }
    
    // a nearest neighbor in the set to p; null if set is empty
    public Point2D nearest(final Point2D p) {
        return nearest(rootNode, CONTAINER, p.x(), p.y(), null);
    }
    
    private Point2D nearest(final KdNode node, final RectHV rect, final double x, final double y,
                            final Point2D candidate) {
        if (node == null) {
            return candidate;
        }
        
        double dqn = 0.0;
        double drq = 0.0;
        RectHV left = null;
        RectHV rigt = null;
        final Point2D query = new Point2D(x, y);
        Point2D nearest = candidate;
        
        if (nearest != null) {
            dqn = query.distanceSquaredTo(nearest);
            drq = rect.distanceSquaredTo(query);
        }
        
        if (nearest == null || dqn > drq) {
            final Point2D point = new Point2D(node.x, node.y);
            if (nearest == null || dqn > query.distanceSquaredTo(point))
                nearest = point;
            
            if (node.isVertical) {
                left = new RectHV(rect.xmin(), rect.ymin(), node.x, rect.ymax());
                rigt = new RectHV(node.x, rect.ymin(), rect.xmax(), rect.ymax());
                
                if (x < node.x) {
                    nearest = nearest(node.leftNode, left, x, y, nearest);
                    nearest = nearest(node.rightNode, rigt, x, y, nearest);
                }
                else {
                    nearest = nearest(node.rightNode, rigt, x, y, nearest);
                    nearest = nearest(node.leftNode, left, x, y, nearest);
                }
            } 
            else {
                left = new RectHV(rect.xmin(), rect.ymin(), rect.xmax(), node.y);
                rigt = new RectHV(rect.xmin(), node.y, rect.xmax(), rect.ymax());
                
                if (y < node.y) {
                    nearest = nearest(node.leftNode, left, x, y, nearest);
                    nearest = nearest(node.rightNode, rigt, x, y, nearest);
                }
                else {
                    nearest = nearest(node.rightNode, rigt, x, y, nearest);
                    nearest = nearest(node.leftNode, left, x, y, nearest);
                }
            }
        }
        
        return nearest;
    }
    
    public static void main(String[] args) {
        
       // String filename = args[0];
       // In in = new In(filename);
        In in = new In("kdtree/input400K.txt");
        StdDraw.show();
        
        // initialize the data structures with N points from standard input
        PointSET brute = new PointSET();
        KdTree kdtree = new KdTree();
        while (!in.isEmpty()) {
            double x = in.readDouble();
            double y = in.readDouble();
            Point2D p = new Point2D(x, y);
            kdtree.insert(p);
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
            for (Point2D p : kdtree.range(rect))
                p.draw();
            
            StdDraw.show();
        }
    }
}
