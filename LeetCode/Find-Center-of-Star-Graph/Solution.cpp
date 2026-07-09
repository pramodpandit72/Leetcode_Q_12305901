1class Solution {
2public:
3    int findCenter(vector<vector<int>>& edges) {
4        
5        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]){
6            return edges[0][0];
7        }
8        return edges[0][1];
9    }
10};