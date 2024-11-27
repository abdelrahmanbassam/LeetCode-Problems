class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int neededSum = 0 ;
        for(int i =0 ; i< nums.size(); i++){
            neededSum =target-nums[i];
            if(mp.find(neededSum) != mp.end())
                return {i,mp[neededSum]};
            mp[nums[i]] = i;
        }
    return{-1};
    }
};