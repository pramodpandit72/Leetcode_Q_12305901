1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        unordered_map<int, int> mp; 
5
6        for (int i = 0; i < nums.size(); i++) {
7            int required = target - nums[i];
8
9            if (mp.find(required) != mp.end()) {
10                return {mp[required], i};
11            }
12
13            mp[nums[i]] = i;
14        }
15
16        return {};
17    }
18};