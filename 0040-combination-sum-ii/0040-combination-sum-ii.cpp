class Solution {
public:
    vector<vector<int>> allValidComps;
    void generateUniqueComps(vector<int>& candidates,vector<int>& curComp,int target, int i){
        if(i >= candidates.size() || target < 0 ){
            if(target == 0)
                allValidComps.push_back(curComp);
            return;
        }
        // if(target - candidates[i] < 0)
        //     return;
        curComp.push_back(candidates[i]);
        generateUniqueComps(candidates,curComp,target - candidates[i],i + 1);

        curComp.pop_back();
        while(i < candidates.size()-1 && candidates[i] == candidates[i+1])
            i++;
        generateUniqueComps(candidates,curComp,target,i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> comp;
        generateUniqueComps(candidates,comp,target,0);
        return allValidComps;

    }
};