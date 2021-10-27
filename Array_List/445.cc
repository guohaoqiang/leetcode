/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* l){
        ListNode* dummy = new ListNode();
        dummy->next = l;
        ListNode* curr = dummy->next;
        ListNode* prev = nullptr;
        ListNode* p = nullptr;
        while (curr){
            p = curr->next;
            curr->next = prev;
            prev = curr;
            curr = p;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = reverse(l1);
        ListNode* p2 = reverse(l2);
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy->next;
        while (p1 || p2 || carry){
            ListNode* node = new ListNode();
            int s = 0;
            if (p1) {
                s += p1->val;
                p1 = p1->next;
            }
            if (p2){
                s += p2->val;
                p2 = p2->next;
            } 
            s += carry;
            node->val = s%10;
            carry = s/10;
            
            node->next = curr;
            curr = node;
        }
        
        return curr;
    }
};
