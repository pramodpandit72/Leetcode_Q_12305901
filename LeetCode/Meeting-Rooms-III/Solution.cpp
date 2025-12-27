1class Solution {
2#define ll long long
3#define pli pair<ll, int>
4public:
5    int mostBooked(int n, vector<vector<int>>& meetings) {
6        sort(meetings.begin(), meetings.end());
7        priority_queue<pli, vector<pli>, greater<pli>> free_rooms,
8            occupied_rooms;
9        vector<int> freq(n, 0);
10
11        // Initially all rooms are free
12        for (int i = 0; i < n; ++i)
13            free_rooms.push({0, i}); //{time,room_no} pair
14
15        // Simulate Job Scheduling
16        for (int i = 0; i < meetings.size(); ++i) {
17            // Add rooms getting free now
18            while (!occupied_rooms.empty() and
19                   occupied_rooms.top().first <= meetings[i][0]) {
20                pli curr = occupied_rooms.top();
21                occupied_rooms.pop();
22                curr.first = 0;
23                free_rooms.push(curr);
24            }
25            // Assign a room to current meeting
26            if (!free_rooms.empty()) {
27                pli curr = free_rooms.top();
28                free_rooms.pop();
29                freq[curr.second]++;
30                curr.first = meetings[i][1];
31                occupied_rooms.push(curr);
32            } else {
33                pli curr = occupied_rooms.top();
34                occupied_rooms.pop();
35                freq[curr.second]++;
36                curr.first += 1LL * (meetings[i][1] - meetings[i][0]);
37                occupied_rooms.push(curr);
38            }
39        }
40        int max_meeting_room;
41        int max_meetings = 0;
42        for (int i = 0; i < n; ++i) {
43            if (freq[i] > max_meetings) {
44                max_meeting_room = i;
45                max_meetings = freq[i];
46            }
47        }
48        return max_meeting_room;
49    }
50};