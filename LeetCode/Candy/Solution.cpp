1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4        int n=ratings.size();
5        vector<int> candies(n,1);
6
7        //Step-1: Assign increasing curve with increasing candies
8        for(int i=1;i<n;++i){
9            if(ratings[i]>ratings[i-1])
10                candies[i] = 1 + candies[i-1];
11        }
12
13        //Step-2: Assign decreasing curve with increasing candies
14        int total = candies[n-1];
15        for(int i=n-1;i>0;--i){
16            if(ratings[i-1]>ratings[i])
17                candies[i-1] = max(candies[i-1],1+candies[i]);
18            total += candies[i-1];
19        }
20        return total;
21    }
22};