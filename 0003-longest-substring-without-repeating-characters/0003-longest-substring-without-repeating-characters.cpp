class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> found;
        int l = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            while(found[s[i]]){
               found[s[l++]] = false;
            }
            found[s[i]] = true;
            ans = max(ans, i - l +1);
        }
        return ans;
    }
};