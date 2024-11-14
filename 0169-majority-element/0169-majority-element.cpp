class Solution {
public:
    int countOcc(vector<int>& nums,int e){
        int ans = 0;
        for(int i = 0 ; i< nums.size(); i++)
            if(nums[i] == e)
                ans++;
        return ans;

    }
    int majH(vector<int>& nums,int l ,int r){
        if(l==r)
            return nums[l];
        int mid = (l+r)/2;
        int lm = majH(nums,l,mid);
        int rm = majH(nums,mid+1,r);
        if(lm == rm)
            return lm;
        int cl = countOcc(nums,lm);
        int cr = countOcc(nums,rm);
        if(cl > cr)
            return lm;
        return rm;
    }
    int majorityElement(vector<int>& nums) {
        return majH(nums,0,nums.size()-1);
    }
};