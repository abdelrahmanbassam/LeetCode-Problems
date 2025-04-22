class Solution {
public:
    bool validWindow(unordered_map<char,int> &tfreq,unordered_map<char,int> &curWindowFreq){
        for(auto &x : tfreq){
            if(curWindowFreq[x.first] < x.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        unordered_map<char,int> tfreq,curWindowFreq;
        for(auto &c : t){
            tfreq[c]++;
        }
        int l = 0 , r = 0,lAns = 0, rAns = 0;
        string ans = "";
        while(l < s.size()){
            while(r < s.size() && !validWindow(tfreq,curWindowFreq)){
                curWindowFreq[s[r]]++;
                r++;
            }
            if(validWindow(tfreq,curWindowFreq)){
               
                if(!(rAns - lAns) || rAns - lAns > r-l){
                    rAns = r;
                    lAns = l;
                }
                    
            }
            curWindowFreq[s[l]]--;
            l++;
        }
        return s.substr(lAns,rAns - lAns);
    }
};