class LRUCache {
    private class Node {
        int key, value;
        Node prev, next;

        Node(int k, int v) {
            this.key = k;
            this.value = v;
        }

        Node() {
            this(0, 0);
        }
    }

    private int capacity, count;
    private Map<Integer, Node> map;
    private Node head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new Node();
        tail = new Node();

        head.next = tail;
        tail.prev = head;
        count = 0;
        map = new HashMap<>();
    }

    public int get(int key) {
        Node n = map.get(key);
        if (n == null) {
            return -1;
        }
        update(n);
        return n.value;

    }

    public void put(int key, int value) {
        Node n = map.get(key);
        if (n != null) {
            n.value = value;
            update(n);
            return;
        }

        if (capacity <= count) {
            Node del = tail.prev;
            remove(del);
            map.remove(del.key);
        }

        Node node = new Node(key, value);
        map.put(key, node);
        add(node);
        count++;
    }

    private void add(Node node) {
        Node n = head.next;
        n.prev = node;
        node.next = n;
        node.prev = head;
        head.next = node;
    }

    private void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void update(Node node) {
        remove(node);
        add(node);
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */