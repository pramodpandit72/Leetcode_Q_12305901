1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4
5        if(s.size() != goal.size()) return false;
6        
7        for(int i = 0; i < s.size(); i++) {
8            if(s == goal) {
9                return true;
10            }
11            char first = s[0];
12            s.erase(s.begin());
13            s.push_back(first);
14        }
15        return false;
16    }
17};