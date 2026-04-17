1class Solution {
2public:
3    string longestPalindrome(string s) {
4        int n = s.size();
5        if(n == 0) return "";
6
7        vector<vector<bool>> dp(n, vector<bool>(n, false));
8
9        int start = 0, maxlen = 1;
10
11        for(int i=0;i<n;i++){
12            dp[i][i] = true;
13        }
14
15        for(int len = 2; len <= n; len++){
16            for(int i = 0; i <= n - len; i++){
17                int j = i + len -1;
18
19                if(s[i] == s[j]){
20                    if(len == 2 || dp[i+1][j-1]){
21                        dp[i][j] = true;
22
23                        if(len > maxlen){
24                            start = i;
25                            maxlen = len;
26                        }
27                    }
28                }
29            }
30        }
31        return s.substr(start, maxlen);
32    }
33};