1class Solution {
2public:
3    bool isIsomorphic(string s, string t) {
4        unordered_map<char, char> mp1;
5        unordered_map<char, char> mp2;
6
7        for(int i = 0; i < s.size(); i++) {
8            if(mp1.count(s[i]) && mp1[s[i]] != t[i]) return false;
9
10            if(mp2.count(t[i]) && mp2[t[i]] != s[i]) return false;
11
12            mp1[s[i]] = t[i];
13            mp2[t[i]] = s[i];
14        }
15        return true;
16    }
17};