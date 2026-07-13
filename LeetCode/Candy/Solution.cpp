1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4        int n = ratings.size();
5        vector<int> candy(n, 1);
6        
7        for(int i = 1; i < n; i++) {
8
9            if(ratings[i] > ratings[i - 1]) {
10                candy[i] = candy[i - 1] + 1;
11            }
12        }
13
14        for(int i = n - 2; i >= 0; i--) {
15            if(ratings[i] > ratings[i + 1]) {
16                candy[i] = max(candy[i], candy[i + 1] + 1);
17            }
18        }
19
20        return accumulate(candy.begin(), candy.end(), 0);
21    }
22};