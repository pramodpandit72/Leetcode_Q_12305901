1class Solution {
2public:
3    int shipWithinDays(vector<int>& weights, int days) {
4        int left = *max_element(weights.begin(), weights.end());
5        int right = accumulate(weights.begin(), weights.end(), 0);
6        int answer = right;
7
8        while(left <= right) {
9            int mid = left + (right - left) / 2;
10
11            int cWeight = 0;
12            int rDays = 1;
13            for(int i = 0; i < weights.size(); i++ ){
14                if(cWeight + weights[i] <= mid) {
15                    cWeight += weights[i];
16                } else {
17                    rDays++;
18                    cWeight = weights[i];
19                }
20            }
21            if(rDays <= days) {
22                answer = mid;
23                right = mid - 1;
24            } else {
25                left = mid + 1;
26            }
27        }
28        return answer;
29    }
30};