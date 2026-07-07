1class Solution {
2public:
3    bool wordPattern(string pattern, string s) {
4        unordered_map<char, string> mp;
5        vector<string> words;
6        stringstream ss(s);
7        string word;
8
9        while(ss >> word) {
10            words.push_back(word);
11        }
12        if(pattern.size() != words.size()) return false;
13
14        for(int i = 0; i < pattern.size(); i++) {
15            if(mp.count(pattern[i])) {
16                if(mp[pattern[i]] != words[i]) return false;
17            } else {
18                for(auto x : mp)
19                    if(x.second == words[i]) return false;
20                
21                mp[pattern[i]] = words[i];
22            }
23        }
24        return true;
25    }
26};