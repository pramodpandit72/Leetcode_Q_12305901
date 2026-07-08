1// class Solution {
2// public:
3//     bool dfs(int node, int destination, vector<vector<int>> &adj, vector<bool> &visited) {
4//         visited[node] = true;
5
6//         if(node == destination) {
7//             return true;
8//         }
9//         for(int neighbor : adj[node]) {
10//             if(!visited[neighbor]){
11//                 if(dfs(neighbor, destination, adj, visited)) {
12//                     return true;
13//                 }
14//             }
15//         }
16//         return false;
17//     }
18
19//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
20//         vector<vector<int>> adj(n);
21
22//         for(auto x : edges) {
23//             int a = x[0];
24//             int b = x[1];
25
26//             adj[a].push_back(b);
27//             adj[b].push_back(a);
28//         }
29
30//         vector<bool> visited(n, false);
31
32//         return dfs(source, destination, adj, visited);
33//     }
34// };
35
36class Solution {
37public:
38    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
39        vector<vector<int>> adj(n);
40
41        for(auto x : edges) {
42            int a = x[0];
43            int b = x[1];
44
45            adj[a].push_back(b);
46            adj[b].push_back(a);
47        }
48
49        vector<bool> visited(n, false);
50        queue<int> q;
51
52        q.push(source);
53        visited[source] = true;
54
55        while(!q.empty()) {
56            int node = q.front();
57            q.pop();
58
59            if(node == destination) {
60                return true;
61            }
62
63            for(int neighbor : adj[node]) {
64                if(!visited[neighbor]) {
65                    visited[neighbor] = true;
66                    q.push(neighbor);
67                }
68            }
69        }
70        return false;
71    }
72};