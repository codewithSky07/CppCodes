class Solution {
public:
    string removeDuplicates(string s) {
        
        // declare the stack
        vector<char>st;
        
        // push index 0.
        st.push_back(s[0]);
        
        // start the loop from index 1.
        for(int i=1;i<s.size();i++){
            // if adjacent are duplicate remove it from stack.
               if(!st.empty() && st.back() == s[i]) {
                   st.pop_back();
               }else{
                   st.push_back(s[i]);
               }
        }
        // convert into string..
        string ans(st.begin(),st.end());
        // return string..
        return ans;
    
    }
};
