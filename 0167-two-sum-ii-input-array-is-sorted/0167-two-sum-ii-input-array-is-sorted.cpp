class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int l = 0 ,r = n.size()-1;
        while(l < r){
            if(n[r] + n[l] == target)
                return {l + 1 ,r + 1};
            else if(n[r] + n[l] > target)
                r--;
            else
                l++;
        }
        return {-1,-1};
    }
};