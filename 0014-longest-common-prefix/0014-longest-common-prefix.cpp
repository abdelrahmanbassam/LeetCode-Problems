class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";
        int i = 0;
        for(auto c : strs[0]){
            for(auto &str : strs){
                if(str.size() <= i || str[i] != c){
                    return ans;
                }
            }
                ans.push_back(c);
                i++;
        }
        return ans;
    }
};