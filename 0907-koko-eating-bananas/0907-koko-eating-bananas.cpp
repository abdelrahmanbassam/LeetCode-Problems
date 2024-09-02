class Solution {
public:
    int calcHours(vector<int>& piles,long long &spead){
        long long ans = 0;
        for(auto &e : piles){
            ans += (e+spead-1)/spead;//ceil
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1 , r = 1e9+1,ans= 0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            long long curH = calcHours(piles,mid);
            if(curH > h || curH < 0)
                l = mid + 1;
            else{
                // ans = mid;
                r = mid - 1;
            }
        }    
        return l;
    }
};
