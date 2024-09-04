class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0,l = 0 ,cur = 0,used = 0;
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
            ans = max(ans,i - l +1);
        }
        return ans;
    }
};