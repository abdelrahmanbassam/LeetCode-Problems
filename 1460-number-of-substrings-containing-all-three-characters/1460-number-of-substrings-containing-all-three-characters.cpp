class Solution {
public:
    bool allThree(vector<int>& freq) {
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
    int numberOfSubstrings(string s) {
      int ans = 0;
      vector<int> freq(3, 0);
      int l = 0 ,r = 0;
      while(r < s.size()){
        freq[s[r]-'a']++;
        while(allThree(freq)){
            ans += s.size() - r;
            freq[s[l]-'a']--;
            l++;
        }
        r++; 
      }
      return ans;
    }
};