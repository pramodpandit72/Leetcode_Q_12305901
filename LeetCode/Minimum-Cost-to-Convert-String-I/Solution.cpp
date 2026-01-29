1class Solution {
2public:
3    void FloydWarshall(vector<vector<long long>>& adjMatrix,
4                       vector<char>& original, vector<char>& changed,
5                       vector<int>& cost) {
6
7        for (int i = 0; i < original.size(); i++) {
8            int s = original[i] - 'a';
9            int t = changed[i] - 'a';
10
11            adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
12        }
13
14        // Apply Floyd Warshall
15        for (int k = 0; k < 26; ++k) {
16            for (int i = 0; i < 26; ++i) {
17                for (int j = 0; j < 26; ++j) {
18                    adjMatrix[i][j] =
19                        min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
20                }
21            }
22        }
23    }
24
25    long long minimumCost(string source, string target, vector<char>& original,
26                          vector<char>& changed, vector<int>& cost) {
27        vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));
28
29        FloydWarshall(
30            adjMatrix, original, changed,
31            cost); // update adjMatrix with shortest path using Floyd Warshall
32
33        long long ans = 0;
34
35        for (int i = 0; i < source.length(); i++) {
36            if (source[i] == target[i]) {
37                continue;
38            }
39
40            if (adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
41                return -1;
42            }
43
44            ans += adjMatrix[source[i] - 'a'][target[i] - 'a'];
45        }
46
47        return ans;
48    }
49};