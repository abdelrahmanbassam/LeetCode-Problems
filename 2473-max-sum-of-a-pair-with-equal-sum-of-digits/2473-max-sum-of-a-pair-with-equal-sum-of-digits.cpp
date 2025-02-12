class Solution {
public:
    int digitsSum(int number){
        int dSum = 0;
        while(number){
            dSum += number%10;
            number /= 10;
        }
        return dSum;
    }
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>> vp;
        for(auto &num : nums){
            vp.push_back({digitsSum(num),num});
        }
        sort(vp.begin(), vp.end());
        int ans = -1;
        for(int i = 1; i < vp.size(); i++){
            if(vp[i].first == vp[i-1].first)
                ans = max(ans,vp[i].second + vp[i-1].second);
        }
        return ans;
    }
};