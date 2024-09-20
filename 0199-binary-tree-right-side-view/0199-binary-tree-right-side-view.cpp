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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};

        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            int rightMost;
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                rightMost = cur->val;
                if(cur->left != NULL)
                    q.push(cur->left);

                if(cur->right != NULL)
                    q.push(cur->right);
                    
            }
            ans.push_back(rightMost);
        }
        return ans;
    }
};