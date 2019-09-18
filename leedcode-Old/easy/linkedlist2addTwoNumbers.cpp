//2. extra Two Numbers
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. extra the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* addTwoNumbers(ListNode* r1, ListNode* r2) {
        ListNode *ans = r1;
        if(!r1) return r2;
        if(!r2) return r1;
        
        int extra = 0;
        int val;
        ListNode* pre = r1;
        while(r1&&r2){
            val = r1->val + r2->val + extra;
            extra = val/10;
            val %= 10;
            r1->val = val;
            
            pre = r1;
            r1=r1->next;
            r2=r2->next;
        }
        //if r2.length > r1.length, append r2's left part to r1
        if(r2){
            pre->next = r2;
            r1 = r2;
        }
        
        //process the single part
        while(r1){
            if(extra){
                pre = r1;
                r1->val += extra;
                extra = r1->val/10;
                r1->val %= 10;
                r1=r1->next;
            }
            else
                break;
        }
        
        if(extra) pre->next = new ListNode(1);
        
        return ans;
        
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        int total;
        int carry = 0;
        while(carry || l1 || l2) {
            total = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = total / 10;
            prev->next = new ListNode(total % 10);
            prev = prev->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
};

class Solution:
# @return a ListNode
def addTwoNumbers(self, l1, l2):
carry = 0
root = n = ListNode(0)
while l1 or l2 or carry:
v1 = v2 = 0
if l1:
v1 = l1.val
l1 = l1.next
if l2:
v2 = l2.val
l2 = l2.next
carry, val = divmod(v1+v2+carry, 10)
n.next = ListNode(val)
n = n.next
return root.next
