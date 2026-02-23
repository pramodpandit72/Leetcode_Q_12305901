1#include <stack>
2#include <unordered_map>
3#include <vector>
4using namespace std;
5
6class Solution {
7public:
8    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
9        unordered_map<int, int> mp;
10        stack<int> st;
11
12        for (int x : nums2) {
13            while (!st.empty() && st.top() < x) {
14                mp[st.top()] = x;
15                st.pop();
16            }
17            st.push(x);
18        }
19
20        while (!st.empty()) {
21            mp[st.top()] = -1;
22            st.pop();
23        }
24
25        vector<int> ans;
26        for (int x : nums1)
27            ans.push_back(mp[x]);
28
29        return ans;
30    }
31};