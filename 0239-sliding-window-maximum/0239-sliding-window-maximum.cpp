class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<int> pq;
        for(int i = 0; i < k; i++){
            freq[nums[i]]++;
            pq.push(nums[i]);
        }
        vector<int> ans;
        ans.push_back(pq.top());
        for(int i = k; i < nums.size();i++){
            pq.push(nums[i]);
            freq[nums[i]]++;
            freq[nums[i-k]]--;
            while(freq[pq.top()] == 0)
                pq.pop();
            ans.push_back(pq.top());
        }
        return ans;
    }
};