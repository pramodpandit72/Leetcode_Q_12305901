1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int maxSum = nums[0];
5        int sum = nums[0];
6
7        for(int i = 1; i < nums.size(); i++) {
8            sum = max(nums[i], sum + nums[i]);
9
10            maxSum = max(maxSum, sum);
11        }
12        return maxSum;
13    }
14};