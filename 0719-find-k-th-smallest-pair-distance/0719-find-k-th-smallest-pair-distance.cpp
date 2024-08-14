class Solution {
public:
    int numberOfDiffsNotGreaterThanP(vector<int>& nums, int p)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        while(i < n)
        {
            while(j < n && nums[j] - nums[i] <= p)
                j++;

            count += j - i - 1;
            i++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0];
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(numberOfDiffsNotGreaterThanP(nums, mid) < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;

    }
};