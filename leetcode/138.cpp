/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node *copyRandomList(Node *head) {
        if(!head ) return head;

        Node *cur=head;
        Node *temp, *newNode;
        while(cur){
            temp = cur;
            cur = cur->next;

            newNode = new Node(temp->val);
            newNode->next = cur;
            temp->next = newNode;
        }

        cur = head;
        while(cur){
            if(cur->random){
             cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head;
        newNode = head->next;
        while(cur){
            //temp points to origial next
            temp = cur->next->next;

            if(temp){
                cur->next->next = temp->next;
            }
            else{
                cur->next->next = NULL;
            }

            //restore the original list
            cur->next = temp;
            cur = temp;

        }
        return newNode;
    }
};