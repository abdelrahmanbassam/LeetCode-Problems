class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(auto e : nums){
            pq.push(e);
        }
        long long op = 0;
        while(pq.size() >= 2){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            if(x >= k )
                break;
            op++;
            pq.push(x * 2 + y);
        }
        return op;
    }
};