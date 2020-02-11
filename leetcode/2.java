/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(0);
        int carry = 0;
        int sum = 0;
        ListNode last;
        ListNode head = res;
        while(l1 != null && l2 != null) {
            sum = l1.val + l2.val + carry;
            carry = sum/10;
            res.next = new ListNode(sum%10);
            l1 = l1.next;
            l2 = l2.next;
            res = res.next;
        }

        last = l1 == null ? l2 : l1;

        while(last != null) {
            sum = last.val + carry;
            carry = sum/10;
            res.next = new ListNode(sum%10);
            last = last.next;
            res = res.next;
        }
        
        if(carry > 0) res.next = new ListNode(carry);

        return head.next;

    }
}