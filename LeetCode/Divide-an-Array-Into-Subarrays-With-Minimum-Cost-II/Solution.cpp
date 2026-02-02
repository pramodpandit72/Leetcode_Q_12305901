1class Solution {
2public:
3    typedef long long ll;
4    typedef pair<ll, ll> P;
5
6    ll minimumCost(vector<int>& nums, int k, int dist) {
7        int n = nums.size();
8
9        set<P> kMinimum; // stores (k-1) minimum elements
10        set<P> remaining;
11
12        ll sum = 0; // stores sum of (k-1) min elements
13
14        int i = 1;
15        while (i - dist < 1) {
16            kMinimum.insert({nums[i], i});
17            sum += nums[i];
18            if (kMinimum.size() > k - 1) {
19                P temp = *kMinimum.rbegin();
20                sum -= temp.first;
21                remaining.insert(temp);
22                kMinimum.erase(temp);
23            }
24            i++;
25        }
26
27        ll result = LONG_MAX; // stores min sum of (k-1) elements
28                              // 0, 1, ...... i
29        while (i < n) {
30            kMinimum.insert({nums[i], i});
31            sum += nums[i];
32
33            if (kMinimum.size() > k - 1) {
34                P temp = *kMinimum.rbegin();
35                sum -= temp.first;
36                remaining.insert(temp);
37                kMinimum.erase(temp);
38            }
39
40            result = min(result, sum);
41
42            // shift window
43            // i-dist wala element will be removed
44            P remove = {nums[i - dist], i - dist};
45            if (kMinimum.count(remove)) {
46                kMinimum.erase(remove);
47                sum -= remove.first;
48
49                if (!remaining.empty()) {
50                    P temp = *remaining.begin();
51                    kMinimum.insert(temp);
52                    sum += temp.first;
53                    remaining.erase(temp);
54                }
55            } else {
56                remaining.erase(remove);
57            }
58
59            i++;
60        }
61
62        return nums[0] + result;
63    }
64};