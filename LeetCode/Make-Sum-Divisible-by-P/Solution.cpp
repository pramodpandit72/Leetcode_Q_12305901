1class Solution {
2public:
3    int minSubarray(vector<int>& nums, int p) {
4        long long total = 0;
5        for (int x : nums)
6            total = (total + x) % p;
7
8        int need = total % p;
9        if (need == 0)
10            return 0;
11
12        unordered_map<int, long long> mp;
13        mp[0] = -1; // prefix before start
14        long long prefix = 0;
15        int res = nums.size();
16
17        for (int i = 0; i < nums.size(); i++) {
18            prefix = (prefix + nums[i]) % p;
19            int target = (prefix - need + p) % p;
20
21            if (mp.count(target)) {
22                res = min(res, i - (int)mp[target]);
23            }
24
25            mp[prefix] = i;
26        }
27
28        return res == nums.size() ? -1 : res;
29    }
30};