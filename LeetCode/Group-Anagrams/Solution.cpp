1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string, vector<string>> mp;
5
6        for (string s : strs) {
7            string key = s;
8            sort(key.begin(), key.end());   
9
10            mp[key].push_back(s);
11        }
12
13        vector<vector<string>> ans;
14
15        for (auto &it : mp) {
16            ans.push_back(it.second);
17        }
18
19        return ans;
20    }
21};