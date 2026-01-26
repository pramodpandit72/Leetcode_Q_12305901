1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
4        sort(begin(arr), end(arr));
5        vector<vector<int>> result;
6        int n = arr.size();
7
8        int minDiff = INT_MAX;
9        for (int i = 1; i < n; i++) {
10            int diff = arr[i] - arr[i - 1];
11            minDiff = min(diff, minDiff);
12        }
13
14        for (int i = 1; i < n; i++) {
15            int diff = arr[i] - arr[i - 1];
16
17            if (diff == minDiff) {
18                result.push_back({arr[i - 1], arr[i]});
19            }
20        }
21
22        return result;
23    }
24};