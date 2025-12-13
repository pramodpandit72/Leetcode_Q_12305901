1class Solution {
2public:
3    bool isValidCode(const string& s) {
4        if (s.empty())
5            return false;
6        for (char c : s) {
7            if (!isalnum(c) && c != '_') {
8                return false;
9            }
10        }
11        return true;
12    }
13
14    vector<string> validateCoupons(vector<string>& code,
15                                   vector<string>& businessLine,
16                                   vector<bool>& isActive) {
17        unordered_set<string> validLines = {"electronics", "grocery",
18                                            "pharmacy", "restaurant"};
19
20        unordered_map<string, vector<string>> grouped;
21
22        int n = code.size();
23        for (int i = 0; i < n; i++) {
24            if (!isActive[i])
25                continue;
26            if (validLines.count(businessLine[i]) == 0)
27                continue;
28            if (!isValidCode(code[i]))
29                continue;
30
31            grouped[businessLine[i]].push_back(code[i]);
32        }
33
34        vector<string> order = {"electronics", "grocery", "pharmacy",
35                                "restaurant"};
36
37        vector<string> result;
38        for (const string& line : order) {
39            auto& v = grouped[line];
40            sort(v.begin(), v.end());
41            result.insert(result.end(), v.begin(), v.end());
42        }
43
44        return result;
45    }
46};