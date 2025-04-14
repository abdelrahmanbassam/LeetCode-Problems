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
    bool isValidBSTHelper(TreeNode* curNode, long minVal,long maxVal){
        if(!curNode)
            return true;
        if(curNode->val <= minVal || curNode->val >= maxVal)
            return false;
        return isValidBSTHelper(curNode->left,minVal,curNode->val) 
        && isValidBSTHelper(curNode->right,curNode->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
       return isValidBSTHelper(root,LONG_MIN,LONG_MAX);
        
    }
};