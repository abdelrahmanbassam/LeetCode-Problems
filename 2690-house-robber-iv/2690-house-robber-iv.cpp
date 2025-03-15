class Solution {
public:
    bool canSteelK(vector<int>& nums, int k, int maxM){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= maxM){
                ans++;
                i++;
            }
        }
        return ans >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 0,r = 1e9+1, ans = -1;
        while(l <= r){
            int mid = (l+r)/2;

            if(canSteelK(nums,k,mid)){
                r = mid -  1;
                ans = mid;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};