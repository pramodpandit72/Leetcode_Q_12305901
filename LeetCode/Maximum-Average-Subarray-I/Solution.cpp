1class Solution {
2public:
3    double findMaxAverage(vector<int>& nums, int k) {
4        int n = nums.size();
5        int sum = 0;
6
7        for(int i = 0; i < k; i++) {
8            sum += nums[i]; 
9        }
10        
11        double maxAvg = (double)sum / k;
12
13        for(int i = k; i < n; i++) {
14            sum += nums[i];
15            sum -= nums[i - k];
16            double avg = (double)sum / k;
17            maxAvg = max(maxAvg, avg);
18        }
19        return maxAvg;
20    }
21};