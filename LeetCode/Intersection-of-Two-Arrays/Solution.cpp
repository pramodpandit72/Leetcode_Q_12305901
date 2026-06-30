1// class Solution {
2// public:
3//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
4//         // unordered_map<int, int> mp;
5//         vector<int> ans;
6//         set<int> s;
7//         for(int i = 0; i < nums1.size(); i++) {
8//             for(int j = 0; j < nums2.size(); j++) {
9//                 if(nums1[i] == nums2[j]){
10//                     s.insert(nums1[i]);
11//                 }
12//             }
13//         }
14//         for(int i : s) {
15//             ans.push_back(i);
16//         }    
17//         return ans;
18//     }
19// };
20
21class Solution {
22public:
23    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
24        unordered_map<int, int> mp;
25        vector<int> ans;
26        
27        for(int i = 0; i < nums1.size(); i++) {
28            mp[nums1[i]]++;
29        }
30        for(int i = 0; i < nums2.size(); i++) {
31            if(mp.count(nums2[i])) {
32                ans.push_back(nums2[i]);
33                mp.erase(nums2[i]);
34            }
35        }
36        return ans;
37    }
38};