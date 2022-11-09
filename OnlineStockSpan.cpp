class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {

    }

    int next(int price) {
        int ans =1;
        while(!st.empty() && st.top().first <= price){
            // pop out the values and update the ans (consicutive smaller values.)
            ans += st.top().second;
            st.pop();

        }
        st.push({price,ans});
        return ans;
    }
};
