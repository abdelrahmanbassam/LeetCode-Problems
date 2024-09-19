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
    int dfs(TreeNode* root, int dir,int len){//-1 for left , 1 for right
        if(root == NULL)
            return len;

        if(dir == 1)//must go to left
            return dfs(root->left, -1, len + 1);
        else
            return dfs(root->right, 1, len + 1);

    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL)
            return maxLen;
        maxLen = max(dfs(root,-1,-1),maxLen);
        maxLen = max(dfs(root,1,-1),maxLen);
        longestZigZag(root->left); 
        longestZigZag(root->right); 
        return maxLen;
    }
};