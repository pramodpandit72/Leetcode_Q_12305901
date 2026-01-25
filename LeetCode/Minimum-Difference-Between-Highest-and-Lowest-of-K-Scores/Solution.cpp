1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4
5        if(k == 1) {
6            return 0;
7        }
8
9        sort(nums.begin(), nums.end());
10        int ans = INT_MAX;
11
12        for(int i = 0; i + k - 1 < nums.size(); i++) {
13            ans = min(ans, nums[i + k - 1] - nums[i]);
14        }
15
16        return ans;
17    }
18};