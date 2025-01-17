class Solution {
public:
    int maxSubArrayHelper(int l, int r, vector<int>& nums){
        if(l == r)
            return nums[l];
        int sumleft = maxSubArrayHelper(l, (l+r)/2, nums);
        int sumRight = maxSubArrayHelper((l+r)/2 +1 , r, nums);
        int sumCross = corssSum(l,r,nums);
        return max(max(sumleft,sumRight),sumCross);
    }
    int corssSum(int l, int r, vector<int>& nums){
        int sum = 0;
        int leftSum = 0, rightSum = 0, mid = (l+r)/2;
        for(int i = mid - 1 ; i >= l ; i--){
            sum += nums[i];
            leftSum = max(leftSum,sum);
        }
        sum = 0;
        for(int i = mid + 1; i <= r; i++){
            sum += nums[i];
            rightSum = max(rightSum,sum);
        }
        return rightSum + leftSum + nums[mid];
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(0,nums.size()-1,nums);
    }
};