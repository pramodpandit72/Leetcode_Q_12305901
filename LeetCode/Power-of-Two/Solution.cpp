1class Solution {
2public:
3    bool isPowerOfTwo(int n) {
4        if (n <= 0) return false;
5        while (n % 2 == 0) {
6            n /= 2;
7        }
8        return n == 1;
9    }
10};
11