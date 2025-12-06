1class Solution {
2public:
3    static constexpr int MOD = 1e9 + 7;
4
5    int countPartitions(vector<int>& nums, int k) {
6        int n = nums.size();
7
8        vector<long long> dp(n + 1, 0), prefix(n + 1, 0);
9        dp[0] = 1;
10        prefix[0] = 1;
11
12        deque<int> maxDQ, minDQ;
13        int L = 0;
14
15        for (int R = 0; R < n; R++) {
16            // Maintain max deque
17            while (!maxDQ.empty() && nums[maxDQ.back()] <= nums[R])
18                maxDQ.pop_back();
19            maxDQ.push_back(R);
20
21            // Maintain min deque
22            while (!minDQ.empty() && nums[minDQ.back()] >= nums[R])
23                minDQ.pop_back();
24            minDQ.push_back(R);
25
26            // Shrink window until valid
27            while (nums[maxDQ.front()] - nums[minDQ.front()] > k) {
28                if (maxDQ.front() == L)
29                    maxDQ.pop_front();
30                if (minDQ.front() == L)
31                    minDQ.pop_front();
32                L++;
33            }
34
35            // DP transition
36            long long ways = prefix[R];
37            if (L > 0) {
38                ways = (ways - prefix[L - 1] + MOD) % MOD;
39            }
40
41            dp[R + 1] = ways;
42            prefix[R + 1] = (prefix[R] + dp[R + 1]) % MOD;
43        }
44
45        return dp[n];
46    }
47};