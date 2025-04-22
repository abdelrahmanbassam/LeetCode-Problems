/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;

        ListNode *slow = head;
        ListNode *twoStep = head;
        while(twoStep){
            twoStep = twoStep->next;
            if(twoStep)
                twoStep = twoStep->next;
                
            if(twoStep == slow)
                return true;
            slow = slow->next;
        }
        return false;

    }
};