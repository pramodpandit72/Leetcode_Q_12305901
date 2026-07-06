1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        unordered_map<int, int> mp;
7
8        for (int& num : nums) {
9            mp[num]++;
10        }
11
12        // index = frequency
13        // Value will be elements
14        // bucket[i] = elements occuring ith time
15        vector<vector<int>> bucket(n + 1);
16
17        for (auto& it : mp) {
18            int element = it.first;
19            int freq = it.second;
20
21            bucket[freq].push_back(element);
22        }
23
24        // Pick from right to left to find max frequency elements
25        vector<int> result;
26        for (int i = n; i >= 0; i--) {
27
28            if (bucket[i].size() == 0)
29                continue;
30
31            int size = bucket.size();
32            while (bucket[i].size() > 0 && k > 0) {
33                result.push_back(bucket[i].back());
34                bucket[i].pop_back();
35                k--;
36            }
37        }
38
39        return result;
40    }
41};