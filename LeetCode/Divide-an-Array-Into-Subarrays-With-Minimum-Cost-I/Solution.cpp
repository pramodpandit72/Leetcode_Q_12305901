1class Solution {
2public:
3    int minimumCost(vector<int>& nums) {
4        int n = nums.size();
5
6        int firstMin = nums[0];
7        int secondMin = INT_MAX;
8        int thirdMin = INT_MAX;
9
10        for (int i = 1; i < n; i++) {
11            if (nums[i] < secondMin) {
12                thirdMin = secondMin;
13                secondMin = nums[i];
14            } else if (nums[i] < thirdMin) {
15                thirdMin = nums[i];
16            }
17        }
18
19        return firstMin + secondMin + thirdMin;
20    }
21};