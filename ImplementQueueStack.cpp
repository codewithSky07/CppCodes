class MyQueue {
public:
 stack<int> st;
    MyQueue() {

    }

    void push(int x) {
        if (st.size() == 0) {
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        push(x);
        st.push(temp);
    }

    int pop() {
        int temp = st.top();
        st.pop();
        return temp;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};
