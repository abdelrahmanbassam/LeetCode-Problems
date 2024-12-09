class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < nums.size()-2; i++ ){
            while(i != 0 && i < nums.size() - 2&& nums[i]==nums[i-1])
                i++;
            int l = i+1,r = nums.size()-1,e=nums[i];
            while(l < r){
                int sum = nums[l]+nums[r];
                if(sum + e == 0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    while(l < nums.size() && nums[l]==nums[l-1]  )
                        l++;
                }
                else if(sum + e > 0)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};