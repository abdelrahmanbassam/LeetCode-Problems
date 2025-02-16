class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int maxFreq = 0, ans = 0 , l = 0 ;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
            maxFreq = max(maxFreq,freq[s[i]]);
            while(i - l + 1 - maxFreq > k){
                freq[s[l++]]--;
            }
            ans = max(ans,i - l +1);
        }
        return ans;
    }
};