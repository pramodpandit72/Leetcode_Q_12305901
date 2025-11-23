class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(3, INT_MIN));

        t[n][0] = 0;      
        t[n][1] = INT_MIN;
        t[n][2] = INT_MIN; 

        for (int i = n - 1; i >= 0; --i) {
            for (int rem = 0; rem < 3; rem++) {

                int newRem = (rem + nums[i]) % 3;
                int pick = (t[i + 1][newRem] == INT_MIN)
                               ? INT_MIN
                               : nums[i] + t[i + 1][newRem];

                int notPick = t[i + 1][rem];

                t[i][rem] = max(pick, notPick);
            }
        }
        return t[0][0];
    }
};