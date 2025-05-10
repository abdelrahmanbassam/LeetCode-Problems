class Solution {
public:
    vector<vector<int>> allComps;
    void subsetsWithDupHelper(vector<int>& nums,int i, vector<int>& curComp){
        if(i >= nums.size()){
            allComps.push_back(curComp);
            return;
        }
        curComp.push_back(nums[i]);
        subsetsWithDupHelper(nums,i+1,curComp);

        curComp.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        subsetsWithDupHelper(nums,i+1,curComp);
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curComp;
        subsetsWithDupHelper(nums,0,curComp);
        return allComps;
    }
};