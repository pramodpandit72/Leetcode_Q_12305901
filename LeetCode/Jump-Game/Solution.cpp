1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int maxReach = 0;
5
6        for(int i = 0; i < nums.size(); i++) {
7            if(i > maxReach) {
8                return false;
9            }
10            maxReach = max(i + nums[i], maxReach);
11            
12            if(maxReach >= nums.size() - 1){
13                return true;
14            }
15        }
16
17        return false;
18    }
19};