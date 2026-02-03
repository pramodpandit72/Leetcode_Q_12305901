1class Solution {
2public:
3    bool isPowerOfFour(int n) {
4        if(n<=0){
5            return false;
6        }
7        while(n%4==0){
8            n/=4;
9        }
10        return n==1;
11    }
12};