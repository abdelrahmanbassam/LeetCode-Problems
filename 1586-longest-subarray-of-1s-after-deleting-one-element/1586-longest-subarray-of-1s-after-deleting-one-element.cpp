class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int z = 0,ans =0,l = 0;
        for(int i = 0; i < nums.size() ; i++){
            z += (nums[i] == 0);
            while(z > 1)
                z -= nums[l++] == 0;
            ans = max(ans,i - l);
        } 
        return ans;
    }
};