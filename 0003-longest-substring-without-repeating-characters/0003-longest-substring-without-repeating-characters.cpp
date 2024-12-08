class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l = 0,ans=0;
        for(int i = 0; i < s.size(); i++){
            while(mp[s[i]]){
                mp[s[l]]--;
                l++;
            }
            mp[s[i]]++;
            ans = max(ans,i-l+1);
        }    
        return ans;
    }
};