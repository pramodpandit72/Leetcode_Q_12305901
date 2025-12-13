1// class Solution {
2// public:
3//     bool isAnagram(string s, string t) {
4//         if (s.size() != t.size())
5//             return false;
6//         vector<int> h(26, 0);
7//         for (int i = 0; i < s.size(); i++) {
8//             h[s[i] - 'a']++;
9//         }
10//         for (int i = 0; i < t.size(); i++) {
11//             int x = --h[t[i] - 'a'];
12//             if (x < 0)
13//                 return false;
14//         }
15//         return true;
16//     }
17// };
18
19class Solution {
20public:
21    bool isAnagram(string s, string t) {
22        if (s.length() != t.length())
23            return false;
24
25        sort(s.begin(), s.end());
26        sort(t.begin(), t.end());
27
28        return s == t;
29    }
30};