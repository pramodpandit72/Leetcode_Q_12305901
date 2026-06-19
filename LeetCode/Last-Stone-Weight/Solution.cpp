1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> pq;
5
6        for(int stone : stones) {
7            pq.push(stone);
8        }
9
10        while(pq.size() > 1) {
11
12            int first = pq.top();
13            pq.pop();
14
15            int second = pq.top();
16            pq.pop();
17
18            if(first != second) {
19                pq.push(first - second);
20            }
21        }
22        if(pq.empty()) {
23            return 0;
24        } else {
25            return pq.top();
26        }
27    }
28};