1class Solution {
2public:
3    long long maxMatrixSum(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6
7        long long sum = 0;
8        int countNegatives = 0;
9        int smallestAbsoluteValue = INT_MAX;
10
11        for (int i = 0; i < m; i++) {
12            for (int j = 0; j < n; j++) {
13                sum += abs(matrix[i][j]);
14
15                countNegatives += matrix[i][j] < 0 ? 1 : 0;
16
17                smallestAbsoluteValue =
18                    min(smallestAbsoluteValue, abs(matrix[i][j]));
19            }
20        }
21
22        if (countNegatives % 2 == 0) {
23            return sum;
24        }
25
26        return sum - 2 * smallestAbsoluteValue;
27    }
28};