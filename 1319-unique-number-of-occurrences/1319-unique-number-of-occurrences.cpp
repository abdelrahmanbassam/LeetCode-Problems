class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occurs;
        for(auto &e : arr){
           occurs[e]++; 
        }    
        unordered_set<int> s;
        for(auto &e : occurs){
            if(s.find(e.second) != s.end()){
                return false;
            }
            s.insert(e.second);
        }
        return true;
    }
};