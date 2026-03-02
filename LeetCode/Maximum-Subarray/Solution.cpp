1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int currSum = nums[0];
5        int maxSum = nums[0];
6
7        for(int i = 1; i < nums.size(); i++){
8            currSum = max(nums[i], currSum + nums[i]);
9            maxSum = max(maxSum, currSum);
10        }
11        return maxSum;
12    }
13};