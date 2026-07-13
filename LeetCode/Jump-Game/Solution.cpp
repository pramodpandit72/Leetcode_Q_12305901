1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int n = nums.size();
5        int maxReach = 0;
6
7        for(int i = 0; i < n; i++) {
8            if(i > maxReach) {
9                return false;
10            }
11            maxReach = max(i + nums[i], maxReach);
12        }
13        if(maxReach >= n - 1){
14            return true;
15        }
16
17        return false;
18    }
19};