1class Solution {
2public:
3    int minPartitions(string n) { 
4        return *max_element(begin(n), end(n)) - '0'; 
5    }
6};