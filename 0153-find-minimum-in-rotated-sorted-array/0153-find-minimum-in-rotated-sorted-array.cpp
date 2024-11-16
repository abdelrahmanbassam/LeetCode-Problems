class Solution {
public:
    int findMinHelper(vector<int>& nums, int l, int r) {
        // Base case: if the range contains only one element
        if (l == r) {
            return nums[l];
        }

        int mid = (l + r) / 2;

        // If the middle element is greater than the last element, 
        // the minimum lies in the right half.
        if (nums[mid] > nums[r]) {
            return findMinHelper(nums, mid + 1, r);
        } 
        // Otherwise, the minimum lies in the left half or at mid.
        else {
            return findMinHelper(nums, l, mid);
        }
    }

    int findMin(vector<int>& nums) {
        return findMinHelper(nums, 0, nums.size() - 1);
    }
};
