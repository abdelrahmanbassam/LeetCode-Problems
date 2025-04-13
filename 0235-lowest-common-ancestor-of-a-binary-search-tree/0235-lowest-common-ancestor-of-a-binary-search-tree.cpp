/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root == q || root == p)
            return root;

        if(min(p->val,q->val) >= root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(max(p->val,q->val) <= root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else   
            return root;
    }
};