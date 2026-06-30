1class Solution {
2public:
3    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
4        // unordered_map<int, int> mp;
5        vector<int> ans;
6        set<int> s;
7        for(int i = 0; i < nums1.size(); i++) {
8            for(int j = 0; j < nums2.size(); j++) {
9                if(nums1[i] == nums2[j]){
10                    s.insert(nums1[i]);
11                }
12            }
13        }
14        for(int i : s) {
15            ans.push_back(i);
16        }
17        
18        return ans;
19    }
20};