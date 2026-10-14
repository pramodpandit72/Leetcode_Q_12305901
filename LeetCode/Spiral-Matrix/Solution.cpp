1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6        vector<int> ans;
7
8        int top = 0;
9        int bottom = m - 1;
10        int left = 0;
11        int right = n - 1;
12
13        while(top <= bottom && left <= right) {
14
15            for(int i = left; i <= right; i++) {
16                ans.push_back(matrix[top][i]);
17            }
18            top++;
19
20            for(int i = top; i <= bottom; i++) {
21                ans.push_back(matrix[i][right]);
22            }
23            right--;
24
25            if(top <= bottom) {
26                for(int i = right; i >= left; i--) {
27                    ans.push_back(matrix[bottom][i]);
28                }
29                bottom--;
30            }
31
32            if(left <= right) {
33                for(int i = bottom; i >= top; i--) {
34                    ans.push_back(matrix[i][left]);
35                }
36                left++;
37            }
38        }
39
40        return ans;
41    }
42};