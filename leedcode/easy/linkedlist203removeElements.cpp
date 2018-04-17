//203. Remove Linked List Elements
//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0), *pre=&dummy, *equalNode;
        dummy.next = head;
        while(head){
            if(head->val == val){
                equalNode = head;
                head = head->next;
                pre->next = head;
                delete equalNode;
            }
            else{
                pre = head;
                head = head->next;
            }
        }
        return dummy.next;
        
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        if(head->val == val){
            return removeElements(head->next, val);
        }
        head->next = removeElements(head->next, val);
        return head;
    }
};
