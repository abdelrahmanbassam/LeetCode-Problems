class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> goodPairs;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int gP = goodPairs[i-nums[i]];
            goodPairs[i-nums[i]]++;
            ans += i - gP;
        }
        return ans;

    }
};      