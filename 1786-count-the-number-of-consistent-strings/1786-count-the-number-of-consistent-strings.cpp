class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        bool f = 1;
        unordered_map<char,bool> ok;
        for(auto &c : allowed){
            ok[c] = true;
        }
        for(auto &s : words){
            f = 1;
            for(auto &c : s){
                if(!ok[c]){
                    f=0;
                    break;
                }
            }
            ans+=f;
        }    
        return ans;
    }
};