//141. Linked List Cycle
//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?
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
	bool hasCycle(ListNode *head) {
		ListNode *walker = head, *runner = head;
		if (!head) return false;

		while (runner->next && runner->next->next) {
			walker = walker->next;
			runner = runner->next->next;
			if (walker == runner) return true;
		}

		return false;
	}
};