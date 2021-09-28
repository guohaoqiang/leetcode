//Iterative solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) { 
        ListNode* dummy = new ListNode(0);
        
        ListNode* before = dummy;
        ListNode* after = head;
        
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        
        while(true){
            ListNode* cursor = after;
            for (int i=0; i<k; ++i){
                if (!cursor){
                    return dummy->next;
                }
                cursor = cursor->next;
            }
            
            curr = after;
            for (int i=0; i<k; ++i){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = nxt;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
};

//Recursive solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* cursor = head;
        for (int i=0; i<k; ++i){
            if (!cursor)
                return head;
            cursor = cursor->next;
        }
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for (int i=0; i<k; ++i){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        head->next = reverseKGroup(curr, k);
        
        return prev;
    }
};
