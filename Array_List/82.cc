class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        prev->next = head;
        ListNode* cur = head;
        while (cur){
            if (cur->next && cur->val==cur->next->val){
                while (cur->next && cur->val==cur->next->val){
                    cur = cur->next;
                }
                prev->next = cur->next;
            }else{
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
