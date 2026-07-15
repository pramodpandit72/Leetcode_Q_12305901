1class Solution {
2public:
3    int gcd(int a, int b) {
4        if (b == 0) return a;
5        return gcd(b, a % b);
6    }
7
8    int gcdOfOddEvenSums(int n) {
9        int odd = n * n;
10        int even = n * (n + 1);
11        return gcd(odd, even);
12    }
13};