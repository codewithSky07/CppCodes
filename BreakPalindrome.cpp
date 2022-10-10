class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size();
        
        if(n<=1) return "";
        
        
        //case2
        
        for(int i=0;i<n/2;i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        // case3
        // replace last char by 'b'
        
        palindrome[n-1] = 'b';
        
        return palindrome;
        
        
    }
};
