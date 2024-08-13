class Solution {
public:

     void helper(vector<int>& num,int i,vector<vector<int>> &res ,vector<int>& sub,int subSum,int tarSum){
       if( i == num.size() || subSum >= tarSum ){
         if(subSum==tarSum)
          res.push_back(sub);
          
         return ;
       }

       sub.push_back(num[i]);
       helper(num,i+1,res,sub,subSum+num[i],tarSum);
      
       sub.pop_back();
        while(i < num.size()-1 &&num[i]==num[i+1] )
         i++;
       helper(num,i+1,res,sub,subSum,tarSum);
       
 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,res,sub,0,target);
        return res;
    }
};