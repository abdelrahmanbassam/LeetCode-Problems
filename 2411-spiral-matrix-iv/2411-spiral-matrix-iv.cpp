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
auto speedUP = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0,y = 0,d = 0;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        while(head != NULL){
            ans[x][y] = head->val;
            int newi = x + dir[d][0], newj = y + dir[d][1];

            if (min(newi, newj) < 0 || newi >= m || newj >= n || ans[newi][newj] != -1)
                d = (d+1)%4;
            x += dir[d][0];
            y += dir[d][1];
            head = head->next;
        }
    return ans;
    }
};