1class Solution {
2public:
3    vector<int> runningSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> prefix(n);
6
7        prefix[0] = nums[0];
8
9        for(int i = 1; i < n; i++) {
10            prefix[i] = prefix[i - 1] + nums[i];
11        }
12        return prefix;
13    }
14};