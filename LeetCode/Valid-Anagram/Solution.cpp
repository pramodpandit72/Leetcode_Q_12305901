1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        if (s.size() != t.size())
5            return false;
6        vector<int> h(26, 0);
7        for (int i = 0; i < s.size(); i++) {
8            h[s[i] - 'a']++;
9        }
10        for (int i = 0; i < t.size(); i++) {
11            int x = --h[t[i] - 'a'];
12            if (x < 0)
13                return false;
14        }
15        return true;
16    }
17};