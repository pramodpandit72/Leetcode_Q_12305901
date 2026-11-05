class Solution {
public:
    int numDecodings(string s) {
            if(s.empty() || s[0] == '0') {
        return 0;
    }

    int n = s.length();
    vector<int> dp(n + 1, 0);
    // Init
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        // Single Digit
        int oneDigit = s[i - 1] - '0';
        if(oneDigit >= 1 && oneDigit <= 9) {
            dp[i] = dp[i] + dp[i - 1];
        }   
        // Two Digits
        int twoDigits = stoi(s.substr(i - 2, 2));

        if(twoDigits >= 10 && twoDigits <= 26) {
            dp[i] = dp[i] + dp[i - 2];
        }
    }
    return dp[n];
    }
};