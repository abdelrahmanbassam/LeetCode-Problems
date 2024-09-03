class Solution {
public:
    vector<int> countBits(int n) {
        int offset = 1;
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i <= n ;i++){
            if(offset*2 == i)
                offset = i;
            ans.push_back(ans[i - offset] + 1);
        }
        return ans;
    }
};