class Solution {
public:
    int maxSubContainMid(vector<int>& nums,int l ,int r){//o(n)
        int mid = (l + r)/2;
        int leftSum = 0;
        int rightSum = 0;
        int sum = 0 ;
        for(int i = mid - 1 ; i >= l ; i--){
            sum+=nums[i];
            leftSum=max(sum, leftSum);
        }

        sum = 0;
        for(int i = mid + 1 ; i <= r ; i++){
            sum+=nums[i];
            rightSum=max(sum, rightSum);
        }
        return nums[mid]+leftSum+rightSum;
    }
    int maxSubArrayHelper(vector<int>& nums,int l ,int r){
        if(l == r)
            return nums[l];
        int mid = (l + r)/2;
        
        int sumLeft =  maxSubArrayHelper(nums,l,mid); 
        int sumRight =  maxSubArrayHelper(nums,mid+1,r);
        int sumMid =  maxSubContainMid(nums,l,r);
        return max(max(sumLeft,sumRight),sumMid);
    }
    int maxSubArray(vector<int>& nums) {
       return  maxSubArrayHelper(nums,0,nums.size()-1);
    }
};