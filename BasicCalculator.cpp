class Solution {
public:
    int calculate(string s) {

        long long int sum = 0;
        int sign = 1;

//         declare stack. {prev_expression_value , sign before next bracket ()}
        stack<pair<int,int>>st;

        for(int i=0;i<s.size();i++){

//             check if it is digit.
            if(isdigit(s[i])){

//                 find the num (Calculate the multi digit number if it is there.)
                long long int num = 0;

                while(i<s.size() && isdigit(s[i])){
                    num = num*10 + (s[i]-'0'); // converting char to integer.
                        i++; // increment the pointer.
                }
//                   decrement 1 as it has moved 1 more after last digit of multi digit number.
//     (If it was there.)

                  i--;

//                 Add value to sum.
                 sum += (num * sign);
                 sign = 1; // reset sign
            }

//             opening bracket. (Save the prev_expression_value , along with sign) in stack.
            else if(s[i] == '('){
                 // Save current state of (sum , sign) in stack
               st.push({sum , sign});

               // For Inner Bracket calculation , Reset sum and sign
               sum = 0;
               sign = 1;
            }


//             closing bracket.   (Add value to the sum along with its sign.)
               else if(s[i] == ')')
           {
               sum = st.top().first + (st.top().second * sum);
               st.pop();
           }

//             "-" symbol. (Change the sign i.e toggle )
              else if(s[i] == '-')
           {
               // Just change the sign. to -ve or +ve .
               sign = (-1 * sign);
           }

        }

        return sum;

    }
};
