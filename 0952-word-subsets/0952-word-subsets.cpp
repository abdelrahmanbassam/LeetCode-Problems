#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getFreq(string &s) {
        vector<int> allFreq(26, 0);
        for (auto &c : s)
            allFreq[c - 'a']++;
        return allFreq;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bMaxFreqs(26, 0);
        vector<string> ans;

        for (auto &s : words2) {
            vector<int> allFreq = getFreq(s);
            for (int i = 0; i < 26; i++) 
                bMaxFreqs[i] = max(bMaxFreqs[i], allFreq[i]);
        }
        for (auto &s : words1) {
            vector<int> curStrFreq = getFreq(s);
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (curStrFreq[i] < bMaxFreqs[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans.push_back(s);
        }
        
        return ans;
    }
};
