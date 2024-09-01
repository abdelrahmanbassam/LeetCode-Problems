class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double curSum = 0 ,ans = 0;
        for(int i = 0 ; i < k ; i++)
            curSum +=nums[i];
        ans = curSum;
        for(int i = k ; i < n ; i++){
            curSum -= nums[i-k];
            curSum += nums[i];
            ans = max(ans,curSum);
        }
        return ans/k;
    }
};
