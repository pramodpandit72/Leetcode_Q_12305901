1class Solution {
2public:
3    bool canConstruct(string ransomNote, string magazine) {
4        unordered_map<char, int> mp;
5
6        for(char i : magazine) {
7            mp[i]++;
8        }
9        for(char i : ransomNote) {
10            if(mp[i] == 0){
11                return false;
12            }
13            mp[i]--;
14        }
15    
16        return true;
17    }
18};