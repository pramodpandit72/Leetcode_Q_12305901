1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        int result = 0;
8
9        for (int i = 0; i < m; i++) {
10            for (int j = 0; j < n; j++) {
11
12                if (grid[i][j] < 0)
13                    result++;
14            }
15        }
16
17        return result;
18    }
19};