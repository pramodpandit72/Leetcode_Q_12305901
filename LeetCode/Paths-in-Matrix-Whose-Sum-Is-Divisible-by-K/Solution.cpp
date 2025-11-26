1class Solution {
2public:
3    int M = 1e9 + 7;
4    vector<vector<vector<int>>> t;
5
6    int solve(int row, int col, int remain, vector<vector<int>>& grid, int k) {
7        int m = grid.size();
8        int n = grid[0].size();
9
10        if (row >= m || col >= n)
11            return 0;
12
13        if (row == m - 1 && col == n - 1)
14            return ((remain + grid[row][col]) % k == 0);
15
16        if (t[row][col][remain] != -1)
17            return t[row][col][remain];
18
19        int newRemain = (remain + grid[row][col]) % k;
20
21        int down = solve(row + 1, col, newRemain, grid, k);
22        int right = solve(row, col + 1, newRemain, grid, k);
23
24        return t[row][col][remain] = (down + right) % M;
25    }
26
27    int numberOfPaths(vector<vector<int>>& grid, int k) {
28        int m = grid.size();
29        int n = grid[0].size();
30
31        t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
32
33        return solve(0, 0, 0, grid, k);
34    }
35};