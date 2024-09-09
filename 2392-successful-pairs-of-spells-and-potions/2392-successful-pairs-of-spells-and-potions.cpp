class Solution {
public:
    int getPairCount(vector<int>& potions, int& spell, long long& target){
        int n = potions.size(), lowestInd = n;
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            long long product = (long long)spell * potions[mid];
            
            if (product >= target){
                lowestInd = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return (n - lowestInd);
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success){
        int n = spells.size();
        vector<int>ans(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) 
            ans[i] = getPairCount(potions, spells[i], success);
        
        return ans;
    }
};