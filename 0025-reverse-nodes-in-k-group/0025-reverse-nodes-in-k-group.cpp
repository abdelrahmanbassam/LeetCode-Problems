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
    int calcSz(ListNode* head){
        ListNode* temp = head;
        int sz = 0;
        while(temp){
            sz++;
            temp = temp->next;
        }
        return sz;
    }
    ListNode* reverseLinkedList(ListNode* head,int sz){
        ListNode* prev = NULL;
        ListNode* headP = head;
         while(headP && sz--){
            ListNode* temp = headP;
            headP = headP->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
    ListNode* reverseKGroupHelper(ListNode* head,int k, int curSZ){
        if(curSZ < k)
            return head;
        ListNode* temp = head;
        for(int i = 0 ;i < k - 1; i++){
            temp = temp->next;
        }
        ListNode* nxt = temp->next;
        ListNode* firstNode = head;
        ListNode* newHead = reverseLinkedList(head,k);
        firstNode->next = reverseKGroupHelper(nxt,k,curSZ - k);
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseKGroupHelper(head,k,calcSz(head));
    }
};