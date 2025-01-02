class Solution {
public:
    bool isV(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pref(words.size() + 1, 0);
        vector<int> ans;

        for (int i = 0; i < words.size(); i++) {
            pref[i + 1] = pref[i] + (isV(words[i][0]) && isV(words[i].back()));
        }

        for (auto &q : queries) {
            ans.push_back(pref[q[1] + 1] - pref[q[0]]);
        }

        return ans;
    }
};
