class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long> pref (nums.size() + 1,0);
        for(int i = 0 ; i < nums.size(); i++){
            pref[i+1] += pref[i] + nums[i];
        }
        int ans = 0,n = nums.size(); 
        for(int i = 1 ; i < n ; i++){
            // cout<< pref[i] << " "<<pref[n] - pref[i] <<endl;
            if(pref[i] >= pref[n] - pref[i])
                ans++;
        }
        return ans;
    }
};