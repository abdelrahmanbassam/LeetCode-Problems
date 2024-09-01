class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int minSz = min(word1.size(),word2.size());
        int maxSz = max(word1.size(),word2.size());
        for(int i = 0 ; i < minSz ; i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        for(int i = minSz ; i < maxSz ; i++){
            if(i < word1.size())
                ans.push_back(word1[i]);
            else
                ans.push_back(word2[i]);
        }
        return ans;
    }
};
