class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // Sort: end ascending, start descending
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1])
                return a[0] > b[0];
            return a[1] < b[1];
        });

        // last two chosen numbers
        int a = -1, b = -1; // a < b always
        int answer = 0;

        for (auto& v : intervals) {
            int L = v[0], R = v[1];

            bool bInside = (b >= L); // b is inside interval
            bool aInside = (a >= L); // a is inside interval

            if (aInside && bInside) {
                // Already has two points
                continue;
            }

            if (bInside) {
                // Has only b inside → need 1 more point
                answer += 1;
                a = b;
                b = R;
            } else {
                // No points inside → pick 2 points
                answer += 2;
                a = R - 1;
                b = R;
            }
        }

        return answer;
    }
};