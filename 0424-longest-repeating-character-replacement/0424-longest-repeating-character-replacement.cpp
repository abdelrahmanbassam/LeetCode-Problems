class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l = 0,ans=0,mxOc = 0 ;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            mxOc = max(mxOc,mp[s[i]]);
            while(i-l+1 - mxOc > k )
                mp[s[l++]]--;
            ans = max(ans, i - l +1);
        }    
        return ans;  
    }
};