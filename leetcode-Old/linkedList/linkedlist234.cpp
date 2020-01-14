//234. Palindrome Linked List
//Given a singly linked list, determine if it is a palindrome.
//
//Follow up :
//Could you do it in O(n) time and O(1) space ?
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		bool ans = true;
		if (!head || !head->next) return true;

		//1. find second list head as fast
		ListNode dummy(0);
		dummy.next = head;
		ListNode *fast = &dummy, *slow = fast, *slowTail, *fastHead;
		while (fast->next&&fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		if (!fast->next) {
			fast = slow->next;
			slowTail = slow;   //for restore
		}
		else {
			fast = slow->next->next;
			slowTail = slow->next; //for restore
		}

		//2. reverse second list
		fast = reverse(fast);
		fastHead = fast;
		//3. compare
		slow = head;
		while (fast) {
			if (fast->val != slow->val) {
				ans = false;
				break;
			}
			else {
				fast = fast->next;
				slow = slow->next;
			}
		}

		//4. restore
		fastHead = reverse(fastHead);
		slowTail->next = fastHead;
		return ans;
	}
	ListNode* reverse(ListNode* head) {
		ListNode *newHead = NULL, *cur;
		while (head) {
			cur = head;
			head = head->next;
			cur->next = newHead;
			newHead = cur;
		}
		return newHead;
	}
};

class Solution {
public:
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		temp = head;
		return check(head);
	}

	bool check(ListNode* p) {
		if (NULL == p) return true;
		bool isPal = check(p->next) & (temp->val == p->val);
		temp = temp->next;
		return isPal;
	}
};

class Solution {
public:
	ListNode* temp;
	bool valid;
	bool isPalindrome(ListNode* head) {
		temp = head;
		valid = true;
		return check(head);
	}

	bool check(ListNode* p) {
		if (NULL == p) return true;
		bool isPal = check(p->next);

		if (!valid) return isPal;

		if (isPal) isPal = temp->val == p->val ? true : false;
		if (temp == p || temp->next == p) valid = false;
		temp = temp->next;
		return isPal;
	}
};