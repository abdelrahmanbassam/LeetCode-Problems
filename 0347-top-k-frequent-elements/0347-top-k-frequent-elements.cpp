class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> occ;
        for (int n : nums) {
            occ[n] += 1;
        }
        auto comp = [&occ](int e1,int e2){
            return occ[e1] > occ[e2];
        };

        priority_queue<int, vector<int>, decltype(comp)> q(comp);

       for (pair<int, int> p : occ) {
            q.push(p.first);
            if (q.size() > k) q.pop();
        }
        vector<int> top(k);
        for (int i = k - 1; i >= 0; i--) {
            top[i] = q.top();
            q.pop();
        }
        return top;
    }
};