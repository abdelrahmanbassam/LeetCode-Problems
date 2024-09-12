class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cands) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        long long  n = costs.size(),i = 0,j = n-1,ans =0 ;

        while(k--){
            while(pq1.size() < cands && i <= j){
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size() < cands && i <= j){
                pq2.push(costs[j]);
                j--;
            }
            int a = pq1.size() ? pq1.top() : INT_MAX;
            int b = pq2.size() ? pq2.top() : INT_MAX;
            if(a <= b)
                pq1.pop();
            else
                pq2.pop();

            ans+=min(a,b);
            
        }
        return ans;
    }
};