1class Solution {
2public:
3    bool repeatedSubstringPattern(string s) {
4        string temp = s + s;
5        temp = temp.substr(1, temp.size() - 2);
6
7        return temp.find(s) != string::npos;
8    }
9};