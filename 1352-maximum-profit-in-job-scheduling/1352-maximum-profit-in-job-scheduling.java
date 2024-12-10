class jop{
    int start;
    int finish;
    int weight;
    jop(int start, int finish, int weight){
        this.start = start;
        this.finish = finish;
        this.weight = weight;
    }

}
class Solution {
    public static int weightedActivitySelection(int[] start, int[] finish, int[] weight) {
        int n = start.length;
        
        jop jops[] = new jop[start.length];
        
        for (int i = 0; i < n; i++) 
            jops[i] = new jop(start[i], finish[i], weight[i]);
        
        Arrays.sort(jops, (a, b) -> a.finish - b.finish);
        int dp[]= new int[n];
        dp[0] = jops[0].weight;

        for(int i = 1; i < n; i++){
            int ind = lastValidJop(jops,jops[i].start);
            if(ind != -1)
                dp[i] = Math.max(dp[i-1], jops[i].weight +dp[ind]);
            else
                dp[i] = Math.max(dp[i-1], jops[i].weight);
        }
        return dp[n-1];

    }
    
    public static int lastValidJop(jop jops[], int start) {
        int ans = -1;
        // for(int i = 0; i < jops.length; i++){
        //     if(jops[i].finish <= start)
        //         ans = i;
        // }
        int  l = 0, r = jops.length - 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(jops[mid].finish <= start){
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1 ;
        }
        return ans;
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        return weightedActivitySelection(startTime,endTime,profit);
    }
}