1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6
7        int i = 0;
8        int j = n - 1;
9        int ans = 0;
10        while(i < j) {
11            ans = max(ans, nums[i] + nums[j]);
12        i++;
13        j--;
14        }
15        return ans;
16    }
17};