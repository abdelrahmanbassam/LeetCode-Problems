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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && subRoot)
            return false;
        if(isSameTree(root,subRoot))
            return true;
        else
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
     bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) 
            return true;
        if (!t1 || !t2) 
            return false;
        if (t1->val != t2->val) 
            return false;

        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
};