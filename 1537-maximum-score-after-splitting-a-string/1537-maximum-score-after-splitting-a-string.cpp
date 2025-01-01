class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        vector<int> manga(s.size() + 1);
        for(int i = 0; i < s.size(); i++){
            manga[i+1] = s[i] == '1'; 
            manga[i+1] += manga[i];
        }
        for(int i = 1; i < s.size(); i++){
            int left = i - manga[i] ;
            int right = manga[s.size()] - manga[i];
            ans =max(ans,left + right);
        }
        return ans;
    }
};