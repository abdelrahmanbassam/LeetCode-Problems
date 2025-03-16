class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> places(26,0),ans;
        int curP = -1,last = -1;
        for(int i = 0 ; i < s.size(); i++){
            places[s[i]-'a'] = i;
        }
        for(int i = 0 ; i < s.size(); i++){
            curP = max(curP,places[s[i]-'a']);
            if(curP == i){
                ans.push_back(i - last);    
                last = i;
            }   
        }
        return ans;
    }
};