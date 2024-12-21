

class Solution {

    class Job {
        int start;
        int end;
        int profit;

        Job(int start, int end, int profit) {
            this.start = start;
            this.end = end;
            this.profit = profit;
        }
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;

        // Step 1: Create an array of jobs
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }

        // Step 2: Sort jobs by finish time
        Arrays.sort(jobs, (a, b) -> a.end - b.end);

        // Step 3: Initialize DP array
        int[] dp = new int[n];
        dp[0] = jobs[0].profit;

        // Step 4: Fill the DP array
        for (int i = 1; i < n; i++) {
            // Find the last job that doesn't overlap with the current job
            int lastIndex = findLastNonConflictingJob(jobs, jobs[i].start);
            
            // Include or exclude the current job
            if (lastIndex != -1) {
                dp[i] = Math.max(dp[i - 1], jobs[i].profit + dp[lastIndex]);
            } else {
                dp[i] = Math.max(dp[i - 1], jobs[i].profit);
            }
        }

        // Step 5: Return the maximum profit
        return dp[n - 1];
    }

    private int findLastNonConflictingJob(Job[] jobs, int currentStart) {
        int low = 0, high = jobs.length - 1, result = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid].end <= currentStart) {
                result = mid; // Potential candidate
                low = mid + 1; // Look for later jobs
            } else {
                high = mid - 1; // Look for earlier jobs
            }
        }

        return result;
    }
}
