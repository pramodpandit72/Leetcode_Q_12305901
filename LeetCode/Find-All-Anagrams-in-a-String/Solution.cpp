1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        vector<int> ans;
5        int n = s.size();
6        int m = p.size();
7
8        if(m > n) return ans;
9
10        vector<int> pfreq(26, 0);
11        vector<int> wfreq(26, 0);
12
13        for(char x : p ) {
14            pfreq[x - 'a']++;
15        }
16
17        for(int i = 0; i < m; i++) {
18            wfreq[s[i] - 'a']++;
19        }
20
21        if(wfreq == pfreq) {
22            ans.push_back(0);
23        }
24
25        for(int i = m; i < n; i++) {
26            wfreq[s[i - m] - 'a']--;
27
28            wfreq[s[i] - 'a']++;
29
30            if(pfreq == wfreq) {
31                ans.push_back(i - m + 1);
32            }
33        }
34
35        return ans;
36    }
37};