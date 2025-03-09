class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        int ans = 0 , l = 0 , r = 1;
        while(r < n){
            while(r < n && colors[r] == colors[r-1]){
                l = r;
                r++;
            }
            if(r - l + 1 == k){
                ans++;
                l++;  
            }
            r++;
        }
        return ans;
    }
};