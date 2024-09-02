class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n + 1);
        for(int i = 0; i < n; i++)
            prefix[i+1]+=prefix[i]+nums[i];
        
        for(int i = 1; i <= n; i++){
            if(prefix[n] - prefix[i] == prefix[i-1])
                return i-1;
        }
        return -1;
    }
};