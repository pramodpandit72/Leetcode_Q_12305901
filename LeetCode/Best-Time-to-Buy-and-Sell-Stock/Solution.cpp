1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int mini=prices[0];
5        int maxProfit=0;
6        int n=prices.size();
7
8        for(int i=0;i<n;i++){
9            int cost=prices[i]-mini;
10            maxProfit=max(maxProfit,cost);
11            mini=min(mini,prices[i]);            
12        }
13        return maxProfit;
14    }
15};