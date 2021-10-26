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
    /*
    ListNode* reverse(ListNode* l){
        ListNode* dummy = new ListNode();
        dummy->next = l;
        ListNode* cur = dummy->next;
        ListNode* prev = nullptr;
        ListNode* p = nullptr;
        while (cur){
            p = cur->next;
            cur->next = prev;
            prev = cur;
            cur = p;
        }
        return dummy->next = prev;
    }
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int fwd = 0;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (p1 && p2){
            ListNode* node = new ListNode((fwd+p1->val+p2->val)%10);
            cur->next = node;
            cur = node;
            fwd = (fwd+p1->val+p2->val)/10;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1){
            ListNode* node = new ListNode((fwd+p1->val)%10);
            cur->next = node;
            cur = node;
            fwd = (fwd+p1->val)/10;
            p1 = p1->next;
        }
        while (p2){
            ListNode* node = new ListNode((fwd+p2->val)%10);
            cur->next = node;
            cur = node;
            fwd = (fwd+p2->val)/10;
            p2 = p2->next;
        }
        if (fwd){
            ListNode* node = new ListNode(fwd);
            cur->next = node;
        }
        return dummy->next;
    }
};
