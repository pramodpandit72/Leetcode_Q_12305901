1class Solution {
2public:
3    string reverseWords(string s) {
4        vector<string> words;
5        vector<string> ans;
6        stringstream str(s);
7
8        string word;
9
10        while(str >> word) {
11            words.push_back(word);
12        }
13
14        int n = words.size();
15        for(int i = n - 1; i >= 0; i--) {
16            ans.push_back(words[i]);
17        }
18        string result;
19        for(int i = 0; i < n; i++) {
20            if(i != 0) {
21                result += " ";
22            }
23            result += ans[i];
24        }
25        return result;
26    }
27};