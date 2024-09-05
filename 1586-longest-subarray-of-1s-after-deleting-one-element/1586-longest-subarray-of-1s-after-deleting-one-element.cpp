class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int ans = 0,l = 0 ,cur = 0,used = 0;
       int  k = 1;
        for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] == 0){
                    if(k == 0){
                        l = i + 1;
                    }
                    else if(used < k){
                        used++;
                    }
                    else{
                        while(l < nums.size() && nums[l] != 0)
                            l++;
                        l++;
                    }

                }
            ans = max(ans,i - l +1 - 1);
        }
        return ans;
    }
};