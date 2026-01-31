1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        for(int i = 0; i < letters.size(); i++) {
5            if(letters[i] > target) {
6                return letters[i];
7            }
8        }
9        return letters[0];
10    }
11};