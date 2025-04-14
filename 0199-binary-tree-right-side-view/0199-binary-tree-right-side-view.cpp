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
        if(!root)
            return {};
        vector<int> ans;
        queue<TreeNode*>q;
        q.push({root});
        while(q.size()){
            int sz = q.size();
            
            for(int i = 0; i < sz; i++){
                TreeNode* curNode = q.front();
                q.pop();
                if(i == 0)
                    ans.push_back(curNode->val);

                if(curNode->right)
                    q.push(curNode->right);
                if(curNode->left)
                    q.push(curNode->left);  
            }
        }
        return ans;
    }
};