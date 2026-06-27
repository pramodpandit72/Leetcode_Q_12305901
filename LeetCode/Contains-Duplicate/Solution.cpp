1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_map<int, int> mp;
5
6        for(int i = 0; i < nums.size(); i++) {
7            mp[nums[i]]++;
8
9            if(mp[nums[i]] > 1) {
10                return true;
11            }
12        }
13        return false;
14    }
15};