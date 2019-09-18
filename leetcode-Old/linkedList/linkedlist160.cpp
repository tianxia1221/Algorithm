//160. Intersection of Two Linked Lists
//
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists:
//
//A:          a1 → a2
//↘
//c1 → c2 → c3
//↗
//B:     b1 → b2 → b3
//begin to intersect at node c1.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        ListNode *slow;
        while(a&&b){
            a = a->next;
            b = b->next;
        }
        
        if(b){
            swap(headA, headB);
            swap(a, b);
        }
        
        slow = headA;
        while(a){
            slow = slow->next;
            a = a->next;
        }
        while(headB && slow){
            if(headB == slow) return slow;
            headB = headB->next;
            slow = slow->next;
        }
        
        return NULL;
        
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *a = headA;
        ListNode *b = headB;
        
        
        if(!headA || !headB) {
            return NULL;
        }
        //@@@df the two linked lists have no intersection at all, then the meeting pointer in second iteration must be the tail node of both lists, which is null
        while( a != b){
            //for the end of first iteration, we just reset the pointer to the head of another linkedlist
            a = a == NULL? headB : a->next;
            b = b == NULL? headA : b->next;
        }
        return a;
        
        
    }
};

//Java
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    int lenA = length(headA), lenB = length(headB);
    // move headA and headB to the same start point
    while (lenA > lenB) {
        headA = headA.next;
        lenA--;
    }
    while (lenA < lenB) {
        headB = headB.next;
        lenB--;
    }
    // find the intersection until end
    while (headA != headB) {
        headA = headA.next;
        headB = headB.next;
    }
    return headA;
}

private int length(ListNode node) {
    int length = 0;
    while (node != null) {
        node = node.next;
        length++;
    }
    return length;
}

//python
class Solution:
# @param two ListNodes
# @return the intersected ListNode
def getIntersectionNode(self, headA, headB):
if headA is None or headB is None:
return None

pa = headA # 2 pointers
pb = headB

while pa is not pb:
# if either pointer hits the end, switch head and continue the second traversal,
# if not hit the end, just move on to next
pa = headB if pa is None else pa.next
pb = headA if pb is None else pb.next

return pa # only 2 ways to get out of the loop, they meet or the both hit the end=None

# the idea is if you switch head, the possible difference between length would be countered.
# On the second traversal, they either hit or miss.
# if they meet, pa or pb would be the node we are looking for,
# if they didn't meet, they will hit the end at the same iteration, pa == pb == None, return either one of them is the same,None
