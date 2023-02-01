class Solution {
public:
 string gcdOfStrings(string str1, string str2) {

        // if they are not same means there is no common substring
        // which can form str1 ,str2 completly.
        // GCD = ""
        if(str1+str2 != str2+str1) return "";
        return str1.substr(0,gcd(str1.length(),str2.length()));
    }
};
