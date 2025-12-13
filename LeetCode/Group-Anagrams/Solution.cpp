1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string, vector<string>> mp;
5
6        for(auto str:strs) {
7            string temp = str;
8            sort(temp.begin(), temp.end());
9            mp[temp].push_back(str);
10        }
11
12        vector<vector<string>> result;
13        for(auto it : mp){
14            result.push_back(it.second);
15        }
16        return result;
17    }
18};