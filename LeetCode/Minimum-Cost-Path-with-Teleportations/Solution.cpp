1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid, int k) {
4        int m = grid.size(), n = grid[0].size();
5        const long long INF = 1e18;
6
7        vector<vector<vector<long long>>> dist(
8            k + 1, vector<vector<long long>>(m, vector<long long>(n, INF)));
9
10        // cells sorted by value
11        vector<tuple<int, int, int>> cells;
12        for (int i = 0; i < m; i++)
13            for (int j = 0; j < n; j++)
14                cells.emplace_back(grid[i][j], i, j);
15        sort(cells.begin(), cells.end());
16
17        // teleport pointers per layer
18        vector<int> ptr(k + 1, 0);
19
20        priority_queue<tuple<long long, int, int, int>,
21                       vector<tuple<long long, int, int, int>>, greater<>>
22            pq;
23
24        dist[0][0][0] = 0;
25        pq.push({0, 0, 0, 0});
26
27        while (!pq.empty()) {
28            auto [cost, t, i, j] = pq.top();
29            pq.pop();
30
31            if (cost != dist[t][i][j])
32                continue;
33            if (i == m - 1 && j == n - 1)
34                return cost;
35
36            // Normal moves
37            if (i + 1 < m) {
38                long long nc = cost + grid[i + 1][j];
39                if (nc < dist[t][i + 1][j]) {
40                    dist[t][i + 1][j] = nc;
41                    pq.push({nc, t, i + 1, j});
42                }
43            }
44            if (j + 1 < n) {
45                long long nc = cost + grid[i][j + 1];
46                if (nc < dist[t][i][j + 1]) {
47                    dist[t][i][j + 1] = nc;
48                    pq.push({nc, t, i, j + 1});
49                }
50            }
51
52            // Teleports (processed lazily & only once)
53            if (t < k) {
54                while (ptr[t] < cells.size() &&
55                       get<0>(cells[ptr[t]]) <= grid[i][j]) {
56                    auto [_, x, y] = cells[ptr[t]];
57                    if (cost < dist[t + 1][x][y]) {
58                        dist[t + 1][x][y] = cost;
59                        pq.push({cost, t + 1, x, y});
60                    }
61                    ptr[t]++;
62                }
63            }
64        }
65
66        return -1;
67    }
68};