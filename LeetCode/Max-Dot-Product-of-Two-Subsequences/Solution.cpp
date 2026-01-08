1class Solution {
2public:
3    int m, n;
4    int t[501][501];
5
6    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
7        if (i == m || j == n)
8            return -100000000; // send a large negative number. Don't send 0
9                               // because we can have -ve product as well. For
10                               // example : {-1, -1}, {1, 1}, output should be
11                               // -1.
12
13        if (t[i][j] != -1e9)
14            return t[i][j];
15
16        int val = nums1[i] * nums2[j];
17
18        int take_i_j = solve(nums1, nums2, i + 1, j + 1) + val;
19
20        int take_i = solve(nums1, nums2, i, j + 1);
21        int take_j = solve(nums1, nums2, i + 1, j);
22
23        return t[i][j] = max({val, take_i_j, take_i, take_j});
24    }
25
26    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
27        m = nums1.size();
28        n = nums2.size();
29
30        for (int i = 0; i < 501; i++) {
31            for (int j = 0; j < 501; j++) {
32                t[i][j] = -1e9;
33            }
34        }
35
36        return solve(nums1, nums2, 0, 0);
37    }
38};