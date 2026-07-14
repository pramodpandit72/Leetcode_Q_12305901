1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4        int n = arr.size();
5        int count = 0;
6        int sum = 0;
7
8        for(int i = 0; i < k; i++) {
9            sum += arr[i];
10        }
11        if(sum / k >= threshold) {
12            count++;
13        }
14        for(int i = k; i < n; i++) {
15            sum += arr[i];
16            sum -= arr[i - k];
17
18            if(sum / k >= threshold) {
19                count++;
20            } 
21        }
22        return count;
23    }
24};