class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
            vector<int> xors(arr.size()+1),ans;
            for(int i = 0; i < arr.size(); i++)
                xors[i+1] = xors[i]^arr[i];
            
            for(auto &v : queries){
                ans.push_back(xors[v[1]+1] ^ xors[v[0]]);
            }
            return ans;
    }
};