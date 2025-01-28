class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        string sorted;
        for(auto &s : strs){
            sorted = s;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(s);
        }
        for(auto &x: mp){
            res.push_back(x.second);
        }
        return res;
    }
};