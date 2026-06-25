1class Solution {
2public:
3    long long hourNeeded(vector<int>& piles, int k) {
4        long long hour = 0;
5
6        for(int p : piles) {
7            hour += (p + k - 1) / k; 
8        }
9        return hour;
10    }
11    int minEatingSpeed(vector<int>& piles, int h) {
12        int low = 1;
13        int high = *max_element(piles.begin(), piles.end());
14        int ans = high;
15
16        while(low <= high) {
17            int mid = low + (high - low) / 2;
18
19            if(hourNeeded(piles, mid) <= h) {
20                ans = mid;
21                high = mid - 1;
22            }else{
23                low = mid + 1;
24            }
25        }
26        return ans;
27    }
28};