1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int maxArea = 0;
5        int left = 0;
6        int right = height.size() - 1;
7
8        while(left < right) {
9            int w = right - left;
10            int h = min(height[left], height[right]);
11
12            maxArea = max(maxArea, w * h);
13
14            if(height[left] < height[right]) {
15                left++;
16            } else {
17                right--;
18            }
19        }
20
21        return maxArea;
22
23
24        // int maxArea = 0;
25
26        // for(int i = 0; i < height.size(); i++) {
27        //     for(int j = i + 1; j < height.size(); j++) {
28        //         int w = j - i;
29        //         int h = min(height[i], height[j]);
30
31        //         maxArea = max(maxArea, h * w);
32        //     }
33        // }
34        // return maxArea;
35    }
36};