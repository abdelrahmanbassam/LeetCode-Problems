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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = head;
        int len = 0;
        while(dummy != NULL){
            len++;
            dummy = dummy->next;
        }
        if(len == 1)
            return NULL;
        len /=2;
        dummy = head;
        while(len-- > 1){
            dummy = dummy->next;
        }
        // if(dummy ->next != NULL)
            dummy->next = dummy ->next->next;
        // else
        //     dummy = NULL;
        return head;

            
    }
};