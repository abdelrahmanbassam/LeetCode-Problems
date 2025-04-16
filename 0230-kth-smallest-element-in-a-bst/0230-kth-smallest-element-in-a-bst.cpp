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
    int curOrder = 0,ans = -1;
    void kthSmallestHelper(TreeNode* root, int &k){
        if(!root)
            return;

        
        kthSmallestHelper(root->left,k);
        curOrder++;
        if(curOrder == k)
            ans = root->val;
        kthSmallestHelper(root->right,k);
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestHelper(root,k);
        return ans;
    }
};