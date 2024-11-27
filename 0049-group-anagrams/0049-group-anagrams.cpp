class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,int> index;
        string sorted;
        for(auto &s : strs){
            sorted = s;
            sort(sorted.begin(),sorted.end());

            if(index.find(sorted) != index.end())
                res[index[sorted]].push_back(s);
            else{
                res.push_back({s});
                index[sorted]=res.size()-1;
            }
        }
        return res;
    }
};