1class Solution {
2public:
3    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
4        unordered_map<int, int> mp;
5        vector<int> ans;
6
7        for(int i : nums1) {
8            mp[i]++;
9        }
10        for(int i : nums2) {
11            if(mp[i] > 0) {
12                ans.push_back(i);
13                mp[i]--;
14            }
15        }
16
17        return ans;
18    }
19};