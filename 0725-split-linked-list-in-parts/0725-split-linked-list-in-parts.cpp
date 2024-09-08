class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            ++len;
            curr = curr->next;
        }

        int partSize = len / k;
        int extra = len % k;

        vector<ListNode*> ans;
        curr = head;
        
        for (int i = 0; i < k; ++i) {
            ListNode* partHead = curr;
            ListNode* partTail = nullptr;
            int currentPartSize = partSize + (extra > 0 ? 1 : 0);
            extra--;
            
            for (int j = 0; j < currentPartSize; ++j) {
                partTail = curr;
                curr = curr->next;
            }
            
            if (partTail) {
                partTail->next = nullptr;
            }
            
            ans.push_back(partHead);
        }
        
        return ans;
    }
};
