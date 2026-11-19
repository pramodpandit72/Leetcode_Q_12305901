class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;

        for (int num : nums)
            freq[num]++;

        while (k--) {
            int maxFreq = 0;
            int element = 0;

            for (auto &it : freq) {
                if (it.second > maxFreq) {
                    maxFreq = it.second;
                    element = it.first;
                }
            }

            ans.push_back(element);
            freq.erase(element);
        }

        return ans;
    }
};