1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int n = haystack.size();
5        int m = needle.size();
6
7        for(int i = 0; i <= n - m; i++) {
8            int j = 0;
9            
10            while(j < m && haystack[i + j] == needle[j]) {
11                j++;
12            }
13            if(j == m) {
14                return i;
15            }
16        }
17        return -1;
18    }
19};