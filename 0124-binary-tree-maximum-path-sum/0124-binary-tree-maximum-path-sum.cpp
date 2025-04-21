/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int res = INT_MIN;
public:
    int getMax(TreeNode* root){
        if(!root)
            return 0;
        int left = getMax(root->left);
        int right = getMax(root->right);
        int path = max(0,root->val + max(left,right));
        return max(path,0);
    }
    void dfs(TreeNode* root){
        if(!root)
            return ;
        res = max(res,root->val);
        int leftSum = getMax(root->left);
        int rightSum = getMax(root->right);
        res = max(res,leftSum + rightSum + root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};