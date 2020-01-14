//Runtime: 20 ms, faster than 98.81% of C++ online submissions for Merge k Sorted Lists.
//Memory Usage: 11.1 MB, less than 69.05% of C++ online submissions for Merge k Sorted Lists.
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return  mergeKLists(lists, 0, lists.size()-1);
	}

	ListNode* mergeKLists(vector<ListNode*>& lists, int low, int high) {
		int n = lists.size();
		if (low > high) return 0;
		if (low == high) return lists[low];
		if (low == high-1) return mergeTwo(lists[low], lists[high]);

		int mid = low + (high - low) / 2;
		ListNode* left = mergeKLists(lists, low, mid);
		ListNode* right = mergeKLists(lists, mid+1, high);
		return mergeTwo(left, right);
	}

	ListNode* mergeTwo(ListNode* a, ListNode* b) {
		ListNode dummy(0);
		ListNode *cur = &dummy;
		while (a && b) {
			if (a->val > b->val) {
				cur->next = b;
				b = b->next;
			}
			else {
				cur->next = a;
				a = a->next;
			}
            cur = cur->next;
		}
		!a ? cur->next = b : cur->next = a;

		return dummy.next;
	}
};