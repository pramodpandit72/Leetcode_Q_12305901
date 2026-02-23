1class Solution {
2public:
3    
4    vector<int> twoSum(vector<int>& nums,int target){
5        map<int,int>mpp;
6        int n=nums.size();
7        for(int i=0;i<n;i++){
8            int num=nums[i];
9            int moreNeeded = target - num;
10            if(mpp.find(moreNeeded) != mpp.end()) {
11                return {mpp[moreNeeded], i};
12            }
13            mpp[num] = i;
14        }
15        return {-1,-1};
16    }
17};