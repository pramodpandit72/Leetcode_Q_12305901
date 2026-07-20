1class Solution {
2public:
3    int numDecodings(string s) {
4            if(s.empty() || s[0] == '0') {
5        return 0;
6    }
7
8    int n = s.length();
9    vector<int> dp(n + 1, 0);
10    // Init
11    dp[0] = 1;
12    dp[1] = 1;
13
14    for(int i = 2; i <= n; i++) {
15        // Single Digit
16        int oneDigit = s[i - 1] - '0';
17        if(oneDigit >= 1 && oneDigit <= 9) {
18            dp[i] = dp[i] + dp[i - 1];
19        }   
20        // Two Digits
21        int twoDigits = stoi(s.substr(i - 2, 2));
22
23        if(twoDigits >= 10 && twoDigits <= 26) {
24            dp[i] = dp[i] + dp[i - 2];
25        }
26    }
27    return dp[n];
28    }
29};