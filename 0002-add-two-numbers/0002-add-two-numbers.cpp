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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        ListNode* sumList = new ListNode(0);
        ListNode* sumListHead = sumList;
        while(l1 && l2){
            int n1 = l1->val;
            int n2 = l2->val;
            int sum = n1 + n2 + rem;
            rem = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            sumList->next = newNode;
            sumList = sumList -> next;
            l1 = l1->next;
            l2 = l2->next; 
        }
        while(l1){
            int n1 = l1->val;
            int sum = n1 + rem;
            rem = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            sumList->next = newNode;
            sumList = sumList -> next;
            l1 = l1->next;
        }
        while(l2){
            int n1 = l2->val;
            int sum = n1 + rem;
            rem = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            sumList->next = newNode;
            sumList = sumList -> next;
            l2 = l2->next;
        }
        if(rem){
            ListNode* newNode = new ListNode(rem);
            sumList->next = newNode;
        }
        return sumListHead->next;
    }
};