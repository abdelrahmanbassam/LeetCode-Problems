
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numsSum = accumulate(nums.begin(), nums.end(), 0);
        if (numsSum % 2 != 0)
            return false;

        int target = numsSum / 2;
        unordered_set<int> sums;
        sums.insert(0);

        for (int e : nums) {
            vector<int> newSums; 

            for (int sum : sums) {
                if (sum + e == target)
                    return true;
                if (sum + e < target)
                    newSums.push_back(sum + e);
            }

            for (int newSum : newSums)
                sums.insert(newSum);
        }

        return false;
    }
};