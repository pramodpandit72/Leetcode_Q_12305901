1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_map<int, int> fq;
5        
6        for(int i : nums) {
7            if(fq[i] > 0) return true;
8            fq[i]++;
9        }
10
11        return false;
12    }
13};