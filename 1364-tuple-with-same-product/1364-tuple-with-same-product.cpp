class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();
        unordered_map<int, int> pairProductsFrequency;

        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength; secondIndex++) {
                pairProductsFrequency[nums[firstIndex] * nums[secondIndex]]++;
            }
        }

        int ans = 0;

        for (auto p : pairProductsFrequency) {
            int pairs = (p.second - 1) * p.second / 2;
            ans += 8 * pairs;
        }

        return ans;
    }
};