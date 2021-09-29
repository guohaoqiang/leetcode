class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* before = nullptr;
        ListNode* after = head;
       
        while (left>1){
            before = after;
            after = after->next;
            left--;
            right--;
        }
        
        ListNode* curr = after;
        ListNode* nxt = nullptr;
        ListNode* prev = before;
        while (right){
            //since left<=right<=n, check nullptr is unnecessary
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
            right--;
        }
        if (before){
            before->next = prev;
        }else {
            head = prev;
        }
        after->next = curr;
        return head;
    }
};
