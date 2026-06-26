1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        int n = nums.size();
5
6        int totalSum = accumulate(nums.begin(), nums.end(), 0);
7
8        int leftSum = 0;
9
10        for(int i = 0; i < n; i++) {
11            int rightSum = totalSum - leftSum - nums[i];
12
13            if(leftSum == rightSum) {
14                return i;
15            }
16
17            leftSum += nums[i];
18        }
19        return -1;
20    }
21};