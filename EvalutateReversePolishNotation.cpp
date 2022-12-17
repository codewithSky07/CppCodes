class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<long> st;
    for(auto s : tokens)
        if(s == "+" || s == "-" || s == "*" || s == "/") {
            long a = st.top(); st.pop();
            long b = st.top(); st.pop();
            if(s == "+") a = b + a;
            if(s == "-") a = b - a;
            if(s == "/") a = b / a;
            if(s == "*") a = (b * a);
            st.push(a);
        }
        // stoi - converts from string to int
        else st.push(stoi(s));
    return st.top();
    }
};
