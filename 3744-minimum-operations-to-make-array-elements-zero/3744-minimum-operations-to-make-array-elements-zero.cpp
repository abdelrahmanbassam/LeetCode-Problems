class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0 ;
        for(auto &q:queries){
            long long ops = 0;
            for(long long d = 1, intervelStart = 1; d < 17; d++){
                long long nextIntervel = intervelStart * 4;
                long long l = max(intervelStart,(long long)q[0]);
                long long r = min(nextIntervel - 1,(long long)q[1]);
                if(r >= l){
                    ops += (r-l+1)*d;
                }
                intervelStart = nextIntervel;
            
            }
            ans += (ops+1)/2;
        }   
    return ans;
    }
};