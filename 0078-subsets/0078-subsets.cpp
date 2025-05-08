class Solution {
public:
    vector<vector<int>> allSubsets;

    void getComps(vector<int>& nums,int i,vector<int>& curComp){
        if(i == nums.size()){
            allSubsets.push_back(curComp);
            return ;
        }
        curComp.push_back(nums[i]);
        getComps(nums,i+1,curComp);
        curComp.pop_back();
        getComps(nums,i+1,curComp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> comp;
        getComps(nums,0,comp);
        return allSubsets;
    }
};