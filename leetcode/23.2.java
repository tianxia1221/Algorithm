// Runtime: 5 ms, faster than 76.88% of Java online submissions for Merge k Sorted Lists.
// Memory Usage: 41.8 MB, less than 33.34% of Java online submissions for Merge k Sorted Lists.
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {

    class NodeCmp implements Comparator<ListNode> {
        public int compare(ListNode a, ListNode b) {
            return a.val - b.val;
        }
    }

    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy = new ListNode(0);
        ListNode top = null;
        ListNode cur = dummy;

        //  PriorityQueue<ListNode> pq = new PriorityQueue<>(new NodeCmp());
        PriorityQueue<ListNode> pq = new PriorityQueue<>((ListNode a, ListNode b) ->  a.val - b.val);
        for(ListNode i: lists)
            if(i!=null) pq.add(i);

        while(pq.size()!=0) {
            top = pq.remove();
            cur.next = top;
            cur = cur.next;
            if(top.next != null) pq.add(top.next);
        }

        return dummy.next;
    }
}
