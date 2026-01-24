1class Solution {
2public:
3    int climbStairs(int n) {
4        vector<int> dp(n + 1);
5
6        if(n <= 2) {
7            return n;
8        }
9        dp[1] = 1;
10        dp[2] = 2;
11        
12        for(int i = 3; i <= n; i++) {
13            dp[i] = dp[i-1] + dp[i-2]; 
14        }
15        return dp[n];
16    }
17};