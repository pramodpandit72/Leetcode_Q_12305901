1class Solution {
2public:
3    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
4        // dp[i] will store all combinations that sum up to i
5        vector<vector<vector<int>>> dp(target + 1);
6
7        // Base: dp[0] = empty combination
8        dp[0].push_back({});
9
10        for (int num : candidates) {
11            for (int t = num; t <= target; t++) {
12                // if there's a way to make (t - num), extend it with num
13                for (auto comb : dp[t - num]) {
14                    comb.push_back(num);
15                    dp[t].push_back(comb);
16                }
17            }
18        }
19
20        return dp[target];
21    }
22};