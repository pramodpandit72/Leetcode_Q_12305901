1class Solution {
2public:
3    typedef pair<int, int> p;
4    vector<int> topKFrequent(vector<int>& nums, int k) {
5
6        priority_queue<p, vector<p>, greater<p>> pq;
7
8        unordered_map<int, int> mp;
9        for(int i : nums)
10            mp[i]++;
11
12        for(auto it:mp) {
13            pq.push({it.second, it.first});
14
15            if(pq.size() > k)
16                pq.pop();
17        }
18
19        vector<int> result;
20        while(!pq.empty()){
21            result.push_back(pq.top().second);
22            pq.pop();
23        }
24        return result;
25    }
26};