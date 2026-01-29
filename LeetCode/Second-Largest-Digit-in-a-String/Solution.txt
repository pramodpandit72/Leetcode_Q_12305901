1class Solution {
2public:
3    int secondHighest(string s) {
4        vector<int> arr;
5        int n = s.size();
6        for(char ch : s) {
7            if(isdigit(ch)) {
8                arr.push_back(ch - '0');
9            }
10        }
11        
12        int larg = -1;
13        int secLarg = -1;
14
15        for(int i = 0; i < arr.size(); i++) {
16            if(arr[i] > larg) {
17                secLarg = larg;
18                larg = arr[i];
19            } else if (arr[i] > secLarg && arr[i] < larg){
20                secLarg = arr[i];
21            }
22        }
23        return secLarg;
24    }
25};