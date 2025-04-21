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
    map<TreeNode*,int> splitSum , withoutSplitSum;
public:
    int maxPathSumHelper(TreeNode* root,bool canSplit) {
        if (!root)
            return 0;
        
        int rightSum = maxPathSumHelper(root->right,false);
        int leftSum = maxPathSumHelper(root->left,false);
        if(canSplit)
            return max(leftSum,0) + max(rightSum,0) + root->val;
        else
            return max(max(leftSum,rightSum),0) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return INT_MIN;
        int sumWithRoot = maxPathSumHelper(root,true);
        int leftTree = maxPathSum(root->left);
        int rightTree = maxPathSum(root->right);
        return max(max(sumWithRoot,leftTree),rightTree);
    }
};