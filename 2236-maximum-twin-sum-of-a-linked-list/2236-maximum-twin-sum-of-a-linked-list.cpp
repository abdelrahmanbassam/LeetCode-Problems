class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        int ans = 0;
        while(pre != NULL){
            ans = max(pre->val + slow->val,ans);
            pre= pre->next;
            slow= slow->next;
        }
        return ans;
    }
};
