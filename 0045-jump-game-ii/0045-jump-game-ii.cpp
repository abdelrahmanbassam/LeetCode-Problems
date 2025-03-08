class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n - 1 ; i++){
            ans++;
            if(i + nums[i] >= n - 1)
                return ans;
            
            int farest = i + nums[i],jump = i;
            for(int j = i ; j <= i + nums[i]; j++){
                if(farest < j + nums[j]){
                    farest = j + nums[j];
                    jump = j;
                }
            }
            i = jump - 1; 
        }
        return ans;
    }
};