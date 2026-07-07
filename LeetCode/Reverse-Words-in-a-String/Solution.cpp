1class Solution {
2public:
3    string reverseWords(string s) {
4        vector<string> words;
5        stringstream str(s);
6        string word;
7
8        while(str >> word) {
9            words.push_back(word);
10        }
11        int n = words.size();
12        string result;
13
14        for(int i = n - 1; i >= 0; i--) {
15            if(i != n - 1){
16                result += " ";
17            }
18            result += words[i];
19        }
20        return result;
21    }
22};