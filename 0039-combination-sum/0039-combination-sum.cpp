class Solution {
public:
    vector<vector<int>> validSubsets;
    void getValidSubset(vector<int>& candidates,vector<int>& curComp, int &target,int i,int curSum){
        if(i == candidates.size() || target <= curSum){
            cout<<curSum<<" ";
            if(target == curSum)
                validSubsets.push_back(curComp);
            return;
        }
        if(curSum + candidates[i] > target)
            return;
        curComp.push_back(candidates[i]);
        curSum += candidates[i];
        getValidSubset(candidates,curComp,target,i,curSum);

        curComp.pop_back();
        curSum -= candidates[i];
        getValidSubset(candidates,curComp,target,i+1,curSum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curComp;
        sort(candidates.begin(),candidates.end());
        getValidSubset(candidates,curComp,target,0,0);
        return validSubsets;
    }
};