1class Solution {
2public:
3    bool isUgly(int n) {
4        if(n <= 0) return false ;
5        while(n % 2 == 0) n/=2;
6        while(n % 3 == 0) n/=3;
7        while(n % 5 == 0) n/=5;
8
9        return n == 1;
10    }
11};