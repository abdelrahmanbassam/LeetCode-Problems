class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            ans += s[i];
            if (ans.size() >= part.size() && ans.substr(ans.size() - part.size()) == part) {
                ans.erase(ans.end() - part.size(), ans.end());
            }
        }
        return ans;
    }
};