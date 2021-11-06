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
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        if (!curr) {
            return head;
        }
        Node* nxt;
        while (curr){
            Node* cp = new Node(curr->val);
            cp->next = curr->next;
            curr->next = cp; 
            curr = curr->next->next;
        }
        
        curr = head;
        while (curr){
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        curr = head;
        Node* new_curr;
        Node* new_head = new Node(0);
        new_head->next = head->next;
        while (curr){
            
            new_curr = curr->next;
            curr->next = new_curr->next;
            if (curr->next)
                new_curr->next = curr->next->next;
            
            curr = curr->next;
        }
        
        return new_head->next;
    }
};
