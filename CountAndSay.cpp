class Solution {
public:
    string countAndSay(int n) {
        // base case.
        if(n == 1) return "1";
        if(n == 2) return "11";

        string s = "11";

        for(int i=3;i<=n;i++){

            string temp="";
            s+="$";   // adding the extra radom string "s" to append count of last value.
            int count=1;

            for(int j=1;j<s.size();j++){

                // if (prev != ith value) we need to add freq then number after it and reintialize it..
                if(s[j-1] != s[j]){
                    temp+=to_string(count); // append the freq.
                    temp+=s[j-1]; // append the value.
                    count=1;  // re intialize it.
                }
                // value is same i.e (prev == ith value) so count++;
                else{
                    count++;
                }
            }

            // update the s with temp.
            s=temp;

        }
        return s;
    }
};
