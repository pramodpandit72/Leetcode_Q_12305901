1class Solution {
2public:
3    int minCostClimbingStairs(vector<int>& cost) {
4        int n = cost.size();
5        vector<int> dp(n);
6
7        dp[0] = cost[0];
8        dp[1] = cost[1];
9
10        for(int i = 2; i < n; i++) {
11            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
12        }
13        
14        return min(dp[n - 1], dp[n - 2]);
15    }
16};