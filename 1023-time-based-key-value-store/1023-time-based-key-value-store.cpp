class TimeMap {
public:
    map<string,vector<pair<string,int>>> tMp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tMp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = tMp[key].size()-1;
        string ans = "";
        while(l <= r){
            int mid = (l+r)/2;
            if(tMp[key][mid].second <= timestamp){
                ans = tMp[key][mid].first;
                l = mid + 1;
            }
            else
                r = mid - 1;
        } 
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */