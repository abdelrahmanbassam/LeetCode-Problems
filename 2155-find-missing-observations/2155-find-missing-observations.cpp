class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int reqSum = (mean*(n+rolls.size())) - accumulate(rolls.begin(),rolls.end(),0);
        if(reqSum < n || reqSum > 6*n)
            return {};
        int comVal = reqSum /n;
        int remVal = reqSum % n;
        
        vector<int>ans(n,comVal);
        for(int i = 0; i < remVal ; i++)
            ans[i]++;
        return ans;
        
    }
};