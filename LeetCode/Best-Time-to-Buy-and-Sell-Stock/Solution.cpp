1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int maxProfit = 0;
5        int minPrice = prices[0];
6        
7        for(int i = 1; i < prices.size(); i++) {
8            int cost = prices[i] - minPrice;
9            maxProfit = max(maxProfit, cost);
10            minPrice = min(minPrice, prices[i]);
11        }
12        return maxProfit;
13    }
14};