1// class Solution {
2// public:
3//     bool checkInclusion(string s1, string s2) {
4//         int n = s1.size();
5//         int m = s2.size();
6//         unordered_map<char, int> need;
7//         unordered_map<char, int> window;
8
9//         if(n > m) return false;
10
11//         for(char x : s1) {
12//             need[x]++;
13//         }
14
15//         for(int i = 0; i < n; i++) {
16//             window[s2[i]]++;
17//         }
18//         if(need == window) return true;
19
20//         for(int i = n; i < m; i++) {
21//             window[s2[i]]++;
22//             window[s2[i - n]]--;
23
24//             if(window[s2[i - n]] == 0) {
25//                 window.erase(s2[i - n]);
26//             }
27
28//             if(window == need) {
29//                 return true;
30//             }
31//         }
32//         return false;
33//     }
34// };
35
36
37class Solution {
38public:
39    bool checkInclusion(string s1, string s2) {
40        int n = s1.size();
41        int m = s2.size();
42        
43        if(n > m) return false;
44        vector<int> need(26, 0);
45        vector<int> window(26, 0);
46
47        for(char x : s1) {
48            need[x - 'a']++;
49        }
50        for(int i = 0; i < n; i++) {
51            window[s2[i] - 'a']++;
52        }
53        if(need == window) return true;
54
55        for(int i = n; i < m; i++) {
56            window[s2[i] - 'a']++;
57            window[s2[i - n] - 'a']--;
58            if(need == window) {
59                return true;
60            }
61        }
62        return false;
63    }
64};