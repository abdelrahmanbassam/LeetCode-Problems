class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> mp;
        string word = "";
        for(char ch : s1){
            if(ch == ' '){
                mp[word]++;
                word = "";
            }
            else
                word += ch;
        }  
        mp[word]++;
        word = "";
        for(char ch : s2){
            if(ch == ' '){
                mp[word]++;
                word = "";
            }
            else
                word += ch;
        }
        
        mp[word]++;
        
        for(auto &i : mp)
            if(i.second == 1) res.push_back(i.first);
        
        return res;
    }
};