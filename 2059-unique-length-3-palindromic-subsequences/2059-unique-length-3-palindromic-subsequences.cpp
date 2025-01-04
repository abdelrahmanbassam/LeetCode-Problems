class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26], last[26];
        fill(begin(first), end(first), -1);
        fill(begin(last), end(last), -1);
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (first[curr] == -1) {
                first[curr] = i;
            }
            last[curr] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) 
                continue; 
            bool between[26] = {false}; 
            for (int j = first[i] + 1; j < last[i]; j++) 
                between[s[j] - 'a'] = true;
            ans += count(begin(between), end(between), true);
        }
        return ans;
    }
};
