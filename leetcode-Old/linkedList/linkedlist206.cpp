//206. Reverse Linked List
//Reverse a singly linked list.

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
	ListNode* reverseList(ListNode* head) {
		ListNode *newHead = NULL, *temp;
		while (head) {
			temp = head;
			head = head->next;

			temp->next = newHead;
			newHead = temp;
		}
		return newHead;
	}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {

		if (!head || !head->next) return head;

		ListNode* nextHead = head->next;

		ListNode* newHead = reverseList(head->next);
		nextHead->next = head;
		head->next = NULL;

		return newHead;
	}
};