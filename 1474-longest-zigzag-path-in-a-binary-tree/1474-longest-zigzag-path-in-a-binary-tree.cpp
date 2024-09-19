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
    int maxLen = 0;
 
    void dfs(TreeNode* node, bool right,int len){
        if(node == NULL)
            return ;

        maxLen = max(len,maxLen);

        if(right){//must go to left
            dfs(node->left, false, len + 1);
            dfs(node->right, true, 1);
        }
        else{
            dfs(node->right, true, len + 1);
            dfs(node->left, false, 1);
        }

    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL)
            return maxLen;
        dfs(root,0,0);
        dfs(root,1,0);
       
        return maxLen;
    }
};