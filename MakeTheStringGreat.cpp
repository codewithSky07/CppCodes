class Solution {
public:
    string makeGood(string s) {
        // declare the stack st.
        vector<char>st;

        st.push_back(s[0]);

        for(int i=1;i<s.size();i++){

            // value at last index. or at the top of stack.
            char topval = st.back();


            // if pair occur i.e one small and one capital
                if( !st.empty() && abs(topval - s[i]) == 32){
                    st.pop_back();
                }else{
                    st.push_back(s[i]);
                }

        }

        // store in string ans.
     string ans(st.begin(), st.end());

        return ans;
    }
};
