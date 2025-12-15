1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& prices) {
4        long long result = 1;
5        long long count = 1;
6
7        for (int i = 1; i < prices.size(); ++i) {
8            if (prices[i - 1] - prices[i] == 1)
9                count++;
10            else
11                count = 1;
12
13            result += count;
14        }
15        return result;
16    }
17};