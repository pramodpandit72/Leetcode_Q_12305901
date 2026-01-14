1class Solution {
2public:
3    struct Event {
4        long long y;
5        int x1, x2;
6        int type; // +1 add, -1 remove
7    };
8
9    struct SegTree {
10        int n;
11        vector<int> cover;
12        vector<long long> len;
13        vector<long long> xs;
14
15        SegTree(int n, const vector<long long>& xs)
16            : n(n), cover(4 * n), len(4 * n), xs(xs) {}
17
18        void pushUp(int idx, int l, int r) {
19            if (cover[idx] > 0) {
20                len[idx] = xs[r] - xs[l];
21            } else if (l + 1 == r) {
22                len[idx] = 0;
23            } else {
24                len[idx] = len[idx * 2] + len[idx * 2 + 1];
25            }
26        }
27
28        void update(int idx, int l, int r, int ql, int qr, int val) {
29            if (ql >= r || qr <= l)
30                return;
31            if (ql <= l && r <= qr) {
32                cover[idx] += val;
33                pushUp(idx, l, r);
34                return;
35            }
36            int m = (l + r) / 2;
37            update(idx * 2, l, m, ql, qr, val);
38            update(idx * 2 + 1, m, r, ql, qr, val);
39            pushUp(idx, l, r);
40        }
41
42        long long query() const { return len[1]; }
43    };
44
45    double separateSquares(vector<vector<int>>& squares) {
46        int n = squares.size();
47        vector<long long> xs;
48        vector<Event> events;
49
50        for (auto& s : squares) {
51            long long x = s[0], y = s[1], l = s[2];
52            xs.push_back(x);
53            xs.push_back(x + l);
54        }
55
56        sort(xs.begin(), xs.end());
57        xs.erase(unique(xs.begin(), xs.end()), xs.end());
58
59        auto getX = [&](long long x) {
60            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
61        };
62
63        for (auto& s : squares) {
64            long long x = s[0], y = s[1], l = s[2];
65            int x1 = getX(x);
66            int x2 = getX(x + l);
67            events.push_back({y, x1, x2, +1});
68            events.push_back({y + l, x1, x2, -1});
69        }
70
71        sort(events.begin(), events.end(),
72             [](const Event& a, const Event& b) { return a.y < b.y; });
73
74        SegTree st(xs.size() - 1, xs);
75
76        long double totalArea = 0;
77        for (int i = 0; i + 1 < events.size(); ++i) {
78            st.update(1, 0, st.n, events[i].x1, events[i].x2, events[i].type);
79            long long dy = events[i + 1].y - events[i].y;
80            if (dy > 0) {
81                totalArea += (long double)st.query() * dy;
82            }
83        }
84
85        long double half = totalArea / 2.0L;
86        long double cur = 0;
87
88        st = SegTree(xs.size() - 1, xs);
89
90        for (int i = 0; i + 1 < events.size(); ++i) {
91            st.update(1, 0, st.n, events[i].x1, events[i].x2, events[i].type);
92            long long dy = events[i + 1].y - events[i].y;
93            if (dy <= 0)
94                continue;
95
96            long double area = (long double)st.query() * dy;
97            if (cur + area >= half) {
98                long double need = half - cur;
99                long double y = events[i].y + need / st.query();
100                return (double)y;
101            }
102            cur += area;
103        }
104
105        return 0.0;
106    }
107};