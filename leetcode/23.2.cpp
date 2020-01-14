//Runtime: 20 ms, faster than 98.81% of C++ online submissions for Merge k Sorted Lists.
//Memory Usage: 11.1 MB, less than 70.24% of C++ online submissions for Merge k Sorted Lists.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

  class node_cmp{
	  public:
      bool operator()(ListNode *a, ListNode *b) {
		  return a->val > b->val;
	  }
  };

  class Solution {
  public:
	  ListNode* mergeKLists(vector<ListNode*>& lists) {
		  ListNode dummy(0);
		  ListNode* cur = &dummy;
		  ListNode* top = nullptr;

          priority_queue<ListNode*, vector<ListNode*>, node_cmp> pq;
		  for (int i = 0; i < lists.size(); i++) {
			  if (lists[i]) pq.push(lists[i]);
		  }

		  while (!pq.empty()) {
			  top = pq.top();
			  pq.pop();
			  cur->next = top;
              cur = cur->next;
			  if (top->next) pq.push(top->next);
		  }

		  return dummy.next;
	  }
  };