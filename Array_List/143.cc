class Solution {
public:
    ListNode* reverse(ListNode* start){
        ListNode* prev = nullptr;
        ListNode* cur = start;
        ListNode* next = nullptr;
        while (cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (!head)  return ;
        
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* next = slow->next;
        slow->next = nullptr;
        
        ListNode* mid = reverse(next);
        ListNode* prev = head;
        ListNode* next1, *next2;
        while (mid){
            next2 = mid->next;
            next1 = prev->next;
            
            prev->next = mid;
            mid->next = next1;
            
            prev = next1;
            mid = next2;
        }
    }
};
