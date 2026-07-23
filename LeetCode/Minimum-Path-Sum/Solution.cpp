1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        vector<vector<int>> dp(m, vector<int> (n, 0));
7        dp[0][0] = grid[0][0];
8
9        for(int i = 1; i < m; i++) {
10            dp[i][0] = grid[i][0] + dp[i - 1][0];
11        }
12        for(int i = 1; i < n; i++) {
13            dp[0][i] = grid[0][i] + dp[0][i - 1];
14        }
15
16        for(int i = 1; i < m; i++) {
17            for(int j = 1; j < n; j++) {
18                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
19            }
20        }
21        return dp[m - 1][n - 1];
22    }
23};