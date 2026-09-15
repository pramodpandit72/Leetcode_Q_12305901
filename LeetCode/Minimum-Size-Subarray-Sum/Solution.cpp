1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int left = 0;
5        int sum = 0;
6        int minLen = INT_MAX;
7        for(int right = 0; right < nums.size(); right++) {
8            sum += nums[right];
9            
10            while(sum >= target) {
11                minLen = min(minLen, right - left + 1);
12                sum -= nums[left];
13                left++;
14            }
15        }
16        if(minLen == INT_MAX) {
17            return 0;
18        }
19        return minLen;
20    }
21};