1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        int n = digits.size();
5        for(int i = n-1; i >= 0; i--){
6            if(digits[i] < 9){
7                digits[i]++;
8                return digits;
9            }
10            digits[i] = 0;
11        }
12        digits.insert(digits.begin(), 1);
13        return digits;
14    }
15};