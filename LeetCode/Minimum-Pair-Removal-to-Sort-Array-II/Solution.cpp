1class Solution {
2public:
3    typedef long long ll;
4
5    int minimumPairRemoval(vector<int>& nums) {
6        int n = nums.size();
7
8        //{a, b, c, d} --> {a, b+c, d}
9        vector<ll> temp(n);
10        for (int i = 0; i < n; i++)
11            temp[i] = nums[i];
12
13        set<pair<ll, int>> minPairSet;
14
15        vector<int> nextIndex(n);
16        vector<int> prevIndex(n);
17
18        for (int i = 0; i < n; i++) {
19            nextIndex[i] = i + 1;
20            prevIndex[i] = i - 1;
21        }
22
23        int badPairs = 0;
24        for (int i = 0; i < n - 1; i++) {
25            if (temp[i] > temp[i + 1]) {
26                badPairs++;
27            }
28            minPairSet.insert({temp[i] + temp[i + 1], i});
29        }
30
31        int operations = 0;
32
33        while (badPairs > 0) {
34            int first = minPairSet.begin()->second;
35            int second = nextIndex[first];
36
37            int first_left = prevIndex[first];
38            int second_right = nextIndex[second];
39
40            minPairSet.erase(begin(minPairSet));
41
42            if (temp[first] > temp[second]) {
43                badPairs--;
44            }
45
46            //{d, (a, b)}
47            if (first_left >= 0) {
48                if (temp[first_left] > temp[first] &&
49                    temp[first_left] <= temp[first] + temp[second]) {
50                    badPairs--;
51                } else if (temp[first_left] <= temp[first] &&
52                           temp[first_left] > temp[first] + temp[second]) {
53                    badPairs++;
54                }
55            }
56
57            //{(a, b), d}
58            if (second_right < n) {
59                if (temp[second_right] >= temp[second] &&
60                    temp[second_right] < temp[first] + temp[second]) {
61                    badPairs++;
62                } else if (temp[second_right] < temp[second] &&
63                           temp[second_right] >= temp[first] + temp[second]) {
64                    badPairs--;
65                }
66            }
67
68            if (first_left >= 0) {
69                minPairSet.erase({temp[first_left] + temp[first], first_left});
70                minPairSet.insert(
71                    {temp[first_left] + temp[first] + temp[second],
72                     first_left});
73            }
74
75            if (second_right < n) {
76                minPairSet.erase({temp[second] + temp[second_right], second});
77                minPairSet.insert(
78                    {temp[first] + temp[second] + temp[second_right], first});
79                prevIndex[second_right] = first;
80            }
81
82            nextIndex[first] = second_right;
83            temp[first] += temp[second];
84
85            operations++;
86        }
87
88        return operations;
89    }
90};