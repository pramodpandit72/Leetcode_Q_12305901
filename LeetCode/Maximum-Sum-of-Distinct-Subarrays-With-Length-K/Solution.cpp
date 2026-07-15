1class Solution {
2public:
3    long long maximumSubarraySum(vector<int>& nums, int k) {
4        int n = nums.size();
5        long long maxSum = 0;
6        long long sum = 0;
7        unordered_map<int, int> mp;
8
9        for(int i = 0; i < k; i++) {
10            sum += nums[i];
11            mp[nums[i]]++;
12        }
13        if(mp.size() == k) {
14            maxSum = sum;
15        }
16
17        for(int i = k; i < n; i++) {
18            sum += nums[i];
19            sum -= nums[i - k];
20            mp[nums[i]]++;
21            mp[nums[i - k]]--;
22            if(mp[nums[i - k]] == 0) {
23                mp.erase(nums[i - k]);
24            }
25
26            if(mp.size() == k) {
27                maxSum = max(sum, maxSum);
28            }
29
30        }
31
32        return maxSum;
33    }
34};