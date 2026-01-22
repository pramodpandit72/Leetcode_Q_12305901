1class Solution {
2public:
3    bool isValidSudoku(vector<vector<char>>& board) {
4        unordered_set<string> st;
5
6        for (int i = 0; i < 9; i++) {
7            for (int j = 0; j < 9; j++) {
8                if (board[i][j] == '.')
9                    continue;
10
11                string row = string(1, board[i][j]) + "_row_" + to_string(i);
12                string col = string(1, board[i][j]) + "_col_" + to_string(j);
13                string box = string(1, board[i][j]) + "_box_" +
14                             to_string(i / 3) + "_" + to_string(j / 3);
15                if (st.count(row) || st.count(col) || st.count(box))
16                    return false;
17                st.insert(row);
18                st.insert(col);
19                st.insert(box);
20            }
21        }
22
23        return true;
24    }
25};
26