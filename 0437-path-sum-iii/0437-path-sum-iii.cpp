/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long ans = 0 ;
    void dfs(TreeNode* root, long long ts){//target sum
        if(root == NULL)
            return;
        if(root->val == ts)
            ans++;
        dfs(root->left,ts-root->val);
        dfs(root->right,ts-root->val);   
    }
    long long pathSum(TreeNode* root, long long targetSum) {
        if(root == NULL)
            return ans;
       
        dfs(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return ans;
    }
     
};