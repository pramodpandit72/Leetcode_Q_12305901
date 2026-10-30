class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word) {
            words.push_back(word);
        }
        if(pattern.size() != words.size()) return false;

        for(int i = 0; i < pattern.size(); i++) {
            if(mp.count(pattern[i])) {
                if(mp[pattern[i]] != words[i]) return false;
            } else {
                for(auto x : mp)
                    if(x.second == words[i]) return false;
                
                mp[pattern[i]] = words[i];
            }
        }
        return true;
    }
};