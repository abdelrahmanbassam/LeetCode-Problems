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
   struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // min-heap based on val
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(auto list : lists){
            if(list)
            pq.push(list);
        }
        ListNode* sorted = new ListNode(0);
        ListNode* trv = sorted;
        while(pq.size()){
            ListNode* node = pq.top();
            pq.pop();
            if(node){
                ListNode* newNode = new  ListNode(node->val);
                node = node->next;
                trv->next = newNode;
                trv = trv->next;
            }
            if(node){
                pq.push(node);
            }
        }
        return sorted->next;
    }
};