class Solution {
public:
    int helper(TreeNode* root,int mx){
        if(root == NULL)
            return 0;
        int add = 0;
        if(root->val >= mx)
            add++;
        mx = max(mx,root->val);

        return add + helper(root->left,mx) + helper(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};
