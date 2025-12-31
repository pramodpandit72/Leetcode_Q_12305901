1class Solution {
2public:
3    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
4        int left = 1, right = row * col;
5        int answer = 0;
6
7        while(left <= right) {
8            int mid = left + (right - left) / 2;
9
10            if(canCross(row, col, cells, mid)) {
11                answer = mid;
12                left = mid + 1;
13            }else{
14                right = mid - 1;
15            }
16        }
17        return answer;
18    }
19
20    private:
21    bool canCross(int row, int col, vector<vector<int>>& cells, int day){
22        vector<vector<int>> grid(row, vector<int>(col, 0));
23
24        for(int i=0;i<day;i++){
25            int r=cells[i][0]-1;
26            int c=cells[i][1]-1;
27            grid[r][c] = 1;
28        }
29
30        queue<pair<int, int>> q;
31        vector<vector<bool>> visited(row, vector<bool>(col, false));
32
33        for(int c = 0; c < col; c++){
34            if(grid[0][c] == 0){
35                q.push({0, c});
36                visited[0][c] = true;
37            }
38        }
39        int dx[4] = {0,0,1,-1};
40        int dy[4] = {1,-1,0,0};
41
42        while(!q.empty()) {
43            auto [x, y] = q.front();
44            q.pop();
45
46            if(x == row - 1)
47                return true;
48
49            for(int d=0;d<4;d++){
50                int nx = x + dx[d];
51                int ny = y + dy[d];
52
53                if(nx >= 0 && ny >= 0 && nx < row && ny < col && !visited[nx][ny] && grid[nx][ny] == 0){
54                    visited[nx][ny] = true;
55                    q.push({nx, ny});
56                }
57            }
58        }
59        return false;
60    }
61};