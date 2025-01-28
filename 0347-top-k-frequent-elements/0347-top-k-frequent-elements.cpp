class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for(auto &e : nums)
            freqs[e]++;

        vector<vector<int>>buckets(nums.size());
        for(auto &e : freqs){
            buckets[e.second-1].push_back(e.first);
        }
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0 && k; i-- ){
            if(!buckets[i].size())
                continue;

            for(auto &e : buckets[i]){
                if(!k)
                    break;
                k--;
                ans.push_back(e);
            }
        }
        return ans;
    }
};