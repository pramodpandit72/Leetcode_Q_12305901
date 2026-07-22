1class Solution {
2public:
3    int minDistance(string word1, string word2) {
4        int m = word1.size();
5        int n = word2.size();
6        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
7
8        for(int i = 1; i <= m; i++) {
9            for(int j = 1; j <= n; j++) {
10                if(word1[i - 1] == word2[j - 1]) {
11                    dp[i][j] = 1 + dp[i - 1][j - 1];
12                }else{
13                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
14                }
15            }
16        }
17        int lcs = dp[m][n];
18
19        return m + n - 2*lcs; 
20    }
21};