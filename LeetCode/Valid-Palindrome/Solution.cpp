1class Solution {
2public:
3    bool isPalindrome(string s) {
4        string str = "";
5
6        for(char c: s) {
7            if(isalnum(c)){
8                str.push_back(tolower(c));
9            }
10        }
11        string rev = str;
12        reverse(rev.begin(), rev.end());
13
14        return rev == str;
15    }
16};