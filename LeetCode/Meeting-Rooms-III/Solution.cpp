1class Solution {
2    #define ll long long
3    #define pli pair<ll,int>
4public:
5    int mostBooked(int n, vector<vector<int>>& meetings) {
6        sort(meetings.begin(),meetings.end());
7        priority_queue<pli,vector<pli>,greater<pli>> free_rooms, occupied_rooms;
8        vector<int> freq(n,0);
9
10        //Initially all rooms are free
11        for(int i=0;i<n;++i)
12            free_rooms.push({0,i});//{time,room_no} pair
13
14        //Simulate Job Scheduling
15        for(int i=0;i<meetings.size();++i){
16            //Add rooms getting free now
17            while(!occupied_rooms.empty() and occupied_rooms.top().first<=meetings[i][0]){
18                pli curr = occupied_rooms.top();
19                occupied_rooms.pop();
20                curr.first = 0;
21                free_rooms.push(curr);
22            }
23            //Assign a room to current meeting
24            if(!free_rooms.empty()){
25                pli curr = free_rooms.top();
26                free_rooms.pop();
27                freq[curr.second]++;
28                curr.first = meetings[i][1];
29                occupied_rooms.push(curr);
30            }else{
31                pli curr = occupied_rooms.top();
32                occupied_rooms.pop();
33                freq[curr.second]++;
34                curr.first += 1LL*(meetings[i][1] - meetings[i][0]);
35                occupied_rooms.push(curr);
36            }
37        }
38        int max_meeting_room;
39        int max_meetings = 0;
40        for(int i=0;i<n;++i){
41            if(freq[i]>max_meetings){
42                max_meeting_room = i;
43                max_meetings = freq[i];
44            }
45        }
46        return max_meeting_room;
47    }
48};