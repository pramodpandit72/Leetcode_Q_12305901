1class Solution {
2public:
3    int minCostClimbingStairs(vector<int>& cost) {
4        int n = cost.size();
5        vector<int> dp(n + 1, 0);
6
7        for(int i = 2; i <= n; i++) {
8            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
9        }
10
11        return dp[n];
12    }
13};