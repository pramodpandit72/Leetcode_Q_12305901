1class Solution {
2public:
3    int M = 1e9 + 7;
4
5    int countPermutations(vector<int>& complexity) {
6        int n = complexity.size();
7
8        long long result = 1;
9
10        for (int i = 1; i < n; i++) {
11            if (complexity[i] <= complexity[0])
12                return 0;
13
14            result = (result * i) % M;
15        }
16        return result;
17    }
18};