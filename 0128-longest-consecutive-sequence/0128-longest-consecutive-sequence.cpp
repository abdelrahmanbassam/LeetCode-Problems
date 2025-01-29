class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> score;
        for(auto &e : nums){
            score[e] = 1;
        }
        int ans = 0 ;
        for(auto &e : score){
           if(e.second == 1){
            int left = 0, right = 0,le = e.first - 1,re = e.first + 1;
            
            while(score.find(le) != score.end() && score[le]){
                score[le] = 0;
                left++;
                le--;
            }
            while(score.find(re) != score.end() && score[re]){
                score[re] = 0;
                right++;
                re++;
            }
            
            ans= max(ans,left + right + 1);
           }
            
            
        }
        return ans;
    }
};