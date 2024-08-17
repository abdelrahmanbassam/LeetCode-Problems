class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int preMn = INT_MAX,preMx = INT_MIN, ans = INT_MIN,curMn,curMx;
        for(int i = 0 ; i < arrays.size() ; i++){
            // curMn = INT_MAX;
            // curMx = INT_MIN;
            curMx = *(arrays[i].end()-1);
            curMn = arrays[i][0];
            if(i){
                ans = max(ans,preMx - curMn);    
                ans = max(ans,curMx - preMn);
            }
            preMn = min(preMn,curMn);
            preMx= max(preMx,curMx);    
        }
          return ans;

        // int n = arrays.size();
        // sort(arrays.begin(),arrays.end());
        // if(n <= 1)
        //     return 0;
        // return *(arrays[n-1].end()-1)-arrays[0][0];
    }
};