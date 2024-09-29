class Solution {
public:
    vector<vector<int>> allComb; // Stores all valid combinations
    
    void helper(int k, int n, int sz, int sum, vector<int>& num, int start) {
        if(sz == k || sum > n) {
            if(sum == n && sz == k)
                allComb.push_back(num);
            return;
        }

        for(int i = start; i < 10; i++) {
            num.push_back(i);       
            helper(k, n, sz + 1, sum + i, num, i + 1);
            num.pop_back();          
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num; 
        helper(k, n, 0, 0, num, 1); 
        return allComb; 
    }
};
