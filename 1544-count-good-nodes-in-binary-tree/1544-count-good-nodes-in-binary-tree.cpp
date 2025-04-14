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
    int dfs(TreeNode* curNode,int maxInPath){
        if(!curNode){
            return 0;
        }
        int add = curNode->val >= maxInPath;
        int left = dfs(curNode->left,max(maxInPath,curNode->val));
        int right = dfs(curNode->right,max(maxInPath,curNode->val));
        return add + left + right;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};