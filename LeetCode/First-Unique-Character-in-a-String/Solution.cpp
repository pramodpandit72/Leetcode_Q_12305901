1class Solution {
2public:
3    int firstUniqChar(string s) {
4        unordered_map<char, int> mp;
5        for(char x : s) {
6            mp[x]++;
7        }
8        for(int i = 0; i < s.size(); i++) {
9            if(mp[s[i]] == 1) return i;
10        }
11
12        return -1;
13    }
14};