1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums,int target){
4        map<int,int>mpp;
5        int n=nums.size();
6        for(int i=0;i<n;i++){
7            int num=nums[i];
8            int moreNeeded = target - num;
9            if(mpp.find(moreNeeded) != mpp.end()) {
10                return {mpp[moreNeeded], i};
11            }
12            mpp[num] = i;
13        }
14        return {-1,-1};
15    }
16};