class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0,curPosSum = 0 ,curNegSum = 0 ;
        for(int i = 0 ; i < nums.size(); i++){
            curPosSum += nums[i];
            curNegSum += nums[i];
            ans = max(ans,max(curPosSum,-1 * curNegSum));
            if(curPosSum < 0)
                curPosSum = 0;
                
            if(curNegSum > 0)
                curNegSum = 0;

        }
        return ans;
    }
};