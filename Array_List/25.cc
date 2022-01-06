class Solution {
public:
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode* prev = end;
        ListNode* cur = start;
        ListNode* next = nullptr;
        
        while (cur!=end){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev; 
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int d = 0;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = head;
        while (cur && d<k-1){
            cur = cur->next;
            d++;
        }
        if (d==k-1) dummy->next = cur;
        
        ListNode* prev = dummy;
        ListNode* next = head;
        cur = head;
        while (next){
            d = 0;
            while (next && d<k){
                next = next->next;
                d++;
            }
            if (d==k) {
                prev->next = reverse(cur,next);
                prev = cur;
                cur = next;
            }else{
                break;
            }
        }
        
        return dummy->next;
    }
};
