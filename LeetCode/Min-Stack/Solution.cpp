1class MinStack {
2private:
3    stack<int> st;
4    stack<int> minst;
5public:
6    MinStack() {
7        
8    }
9    
10    void push(int val) {
11        st.push(val);
12        if(minst.empty() || val <= minst.top()){
13            minst.push(val);
14        }
15    }
16    
17    void pop() {
18        if(st.top() == minst.top()){
19            minst.pop();
20        }
21        st.pop();
22    }
23    
24    int top() {
25        return st.top();
26    }
27    
28    int getMin() {
29        return minst.top();
30    }
31};
32
33/**
34 * Your MinStack object will be instantiated and called as such:
35 * MinStack* obj = new MinStack();
36 * obj->push(val);
37 * obj->pop();
38 * int param_3 = obj->top();
39 * int param_4 = obj->getMin();
40 */