class Solution {
public:  
    int findTheWinner(int n, int k) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int i=n;
        while (i){
            cur->next = new ListNode(n-i+1);
            cur = cur->next;
            i--;
        }
        cur->next = dummy->next;
        if (k==1)   return n;
        ListNode* prev = dummy;
        cur = dummy->next;
        int c = k;
        while (cur!=cur->next){
            while (c>1){
                cur = cur->next;
                prev = prev->next;
                c--;
            }
            cur = prev->next->next;
            prev->next = prev->next->next;
            c = k;
        }
        return cur->val;
    }
};
