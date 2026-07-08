1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4
5        return haystack.find(needle);
6        // int n = haystack.size();
7        // int m = needle.size();
8
9        // for(int i = 0; i <= n - m; i++) {
10        //     int j = 0;
11            
12        //     while(j < m && haystack[i + j] == needle[j]) {
13        //         j++;
14        //     }
15        //     if(j == m) {
16        //         return i;
17        //     }
18        // }
19        // return -1;
20    }
21};