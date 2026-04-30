1class Solution {
2public:
3    int reverse(int x) {
4        long int r=0;
5        while(x!=0){
6            int digit=x%10;
7            if(r>INT_MAX/10 || r<INT_MIN/10){
8                return 0;
9            }
10            r=r*10+digit;
11            x/=10;
12        }
13
14        return r;
15    }
16};