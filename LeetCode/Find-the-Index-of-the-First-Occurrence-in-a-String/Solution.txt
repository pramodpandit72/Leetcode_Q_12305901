1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        if (needle.size() == 0)
5            return 0;
6
7        size_t pos = haystack.find(needle);
8        return pos == string::npos ? -1 : (int)pos;
9    }
10};