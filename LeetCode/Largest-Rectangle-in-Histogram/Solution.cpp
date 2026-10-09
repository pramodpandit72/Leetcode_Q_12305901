1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        stack<int> st;
5        int maxArea = 0;
6        int n = heights.size();
7
8        for (int i = 0; i <= n; i++) {
9            int currHeight = (i == n ? 0 : heights[i]);
10
11            while (!st.empty() && currHeight < heights[st.top()]) {
12                int height = heights[st.top()];
13                st.pop();
14
15                int width;
16                if (st.empty()) {
17                    width = i;
18                } else {
19                    width = i - st.top() - 1;
20                }
21
22                maxArea = max(maxArea, height * width);
23            }
24
25            st.push(i);
26        }
27
28        return maxArea;
29    }
30};