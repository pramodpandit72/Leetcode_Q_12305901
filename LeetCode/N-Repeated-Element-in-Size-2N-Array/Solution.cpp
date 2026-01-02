1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        unordered_set<int> st;
5
6        for (int& num : nums) {
7            if (st.count(num))
8                return num;
9
10            st.insert(num);
11        }
12
13        return -1;
14    }
15};