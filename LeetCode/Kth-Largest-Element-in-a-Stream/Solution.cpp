1class KthLargest {
2public:
3    priority_queue<int, vector<int>, greater<int>> pq;
4
5    int k;
6
7    KthLargest(int k, vector<int>& nums) {
8        this->k = k;
9
10        for(int nums : nums) {
11            pq.push(nums);
12
13            if(pq.size() > k) {
14                pq.pop();
15            }
16        }
17    }
18    
19    int add(int val) {
20        pq.push(val);
21
22        if(pq.size() > k) {
23            pq.pop();
24        }
25        return pq.top();
26    }
27};
28
29/**
30 * Your KthLargest object will be instantiated and called as such:
31 * KthLargest* obj = new KthLargest(k, nums);
32 * int param_1 = obj->add(val);
33 */