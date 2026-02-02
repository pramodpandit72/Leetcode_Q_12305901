1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5        for(int i=0;i<s.length();i++){
6            char ch = s[i];
7            if(ch=='(' || ch=='{' || ch=='['){
8                st.push(ch);
9            }else{
10                if(!st.empty()){
11                    if(ch==')' && st.top()=='(' ||
12                       ch=='}' && st.top()=='{' || 
13                       ch==']' && st.top()=='['){
14                        st.pop();
15                    }else{
16                        return false;
17                    }
18                }else{
19                    return false;
20                }
21            }
22        }
23        if(st.empty()){
24            return true;
25        }else{
26            return false;
27        }
28    }
29};