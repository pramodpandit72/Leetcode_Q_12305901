1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int n = points.size();
5
6        int steps = 0;
7
8        for (int i = 0; i < n - 1;i++) { 
9            // We have to reach the last point - points[n-1]
10            int x1 = points[i][0];
11            int y1 = points[i][1];
12
13            int x2 = points[i + 1][0];
14            int y2 = points[i + 1][1];
15
16            int dx = abs(x2 - x1);
17            int dy = abs(y2 - y1);
18
19            int diagonal = min(dx, dy);
20            int remain = abs(dx - dy);
21
22            steps += diagonal + remain;
23        }
24
25        return steps;
26    }
27};