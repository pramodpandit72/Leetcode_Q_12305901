1class Solution {
2public:
3    void rotate(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        if(n == 0) {
7            return;
8        }
9        k = k % n;
10
11        reverse(nums.begin(), nums.end());
12        reverse(nums.begin(), nums.begin() + k);
13        reverse(nums.begin() + k, nums.end());
14        
15    }
16};