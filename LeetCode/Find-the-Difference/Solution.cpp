1// class Solution {
2// public:
3//     char findTheDifference(string s, string t) {
4//         unordered_map<char, int> mp;
5//         char ans;
6//         for(char i : s) {
7//             mp[i]++;
8//         }
9
10//         for(char i : t) {
11//             mp[i]--;
12//         }
13//         for(auto &i : mp) {
14//             if(i.second != 0) {
15//                 return i.first;
16//             }
17//         }
18
19//         return '\0';
20//     }
21// };
22
23class Solution {
24public:
25    char findTheDifference(string s, string t) {
26        int sum = 0;
27        for(char i : t) {
28            sum += i;
29        }
30        for(char i : s) {
31            sum -=i;
32        }
33        return (char)sum;
34    }
35};