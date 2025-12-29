1class Solution {
2public:
3    unordered_map<string, bool> t;
4
5    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx,
6               string above) {
7        if (curr.length() == 1) { // pyramid is formed and we are at the top
8            return true;
9        }
10
11        string key = curr + "_" + to_string(idx) + "_" + above;
12
13        if (t.count(key))
14            return t[key];
15
16        if (idx ==
17            curr.length() - 1) { // time to move to next row i.e. abocve row
18            return t[key] = solve(above, mp, 0, "");
19        }
20
21        string pair = curr.substr(idx, 2);
22        if (mp.find(pair) == mp.end()) {
23            return t[key] = false;
24        }
25
26        for (char& ch : mp[pair]) {
27            above.push_back(ch); // DO
28
29            if (solve(curr, mp, idx + 1, above) == true) // EXPLORE
30                return t[key] = true;
31
32            above.pop_back(); // UNDO
33        }
34
35        return t[key] = false;
36    }
37
38    bool pyramidTransition(string bottom, vector<string>& allowed) {
39        unordered_map<string, vector<char>> mp;
40
41        for (auto& pattern : allowed) {
42            mp[pattern.substr(0, 2)].push_back(pattern[2]); //"ABC"
43        }
44
45        return solve(bottom, mp, 0, "");
46    }
47};