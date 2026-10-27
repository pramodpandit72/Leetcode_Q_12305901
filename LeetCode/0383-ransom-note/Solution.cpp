class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        for(char i : magazine) {
            mp[i]++;
        }
        for(char i : ransomNote) {
            if(mp[i] == 0){
                return false;
            }
            mp[i]--;
        }
    
        return true;
    }
};