/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxLv = 1 ,maxSum = root->val;
        queue<TreeNode*>q;
        q.push(root);
        int i = 1;
        while(q.size()){
            int sz = q.size();
            int curSum = 0;
            while(sz--){
                TreeNode* curNode = q.front();
                curSum += curNode->val;
                if(curNode->left != NULL)
                    q.push(curNode->left);

                if(curNode->right != NULL)
                    q.push(curNode->right);
                q.pop();
            }
            if(curSum > maxSum){
                maxLv = i;
                maxSum = curSum;
            }
            i++;
        }
        return maxLv;
    }
};