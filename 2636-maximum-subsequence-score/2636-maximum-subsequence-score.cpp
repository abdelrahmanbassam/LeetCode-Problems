class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        long long n = nums1.size();
        for(long long i = 0 ; i < n ; i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end(),greater<pair<long long,long long>>());
        long long ans = 0,curSum = 0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto &[n2,n1] : v){
            curSum+=n1;
            pq.push(n1);
            while(pq.size() > k){
                curSum-=pq.top();
                pq.pop();
            }
            if(pq.size() == k)
                ans = max(ans,curSum*n2);
        }
        return ans;

    }
};