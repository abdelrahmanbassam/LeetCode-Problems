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
    int getSize(ListNode* head){
        ListNode* temp = head;
        int sz = 0 ;
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }
        return sz;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = getSize(head);
        if(!head || n == sz)
            return head->next;

        int ind = sz - n,curI = 1;
        ListNode* temp = head;
        while(curI < ind){
            curI++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};