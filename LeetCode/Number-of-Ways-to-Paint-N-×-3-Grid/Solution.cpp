1class Solution {
2public:
3    int numOfWays(int n) {
4        const int MOD = 1e9 + 7;
5
6        long long a = 6; // Type A: ABA
7        long long b = 6; // Type B: ABC
8
9        for (int i = 2; i <= n; i++) {
10            long long newA = (3 * a + 2 * b) % MOD;
11            long long newB = (2 * a + 2 * b) % MOD;
12            a = newA;
13            b = newB;
14        }
15
16        return (a + b) % MOD;
17    }
18};