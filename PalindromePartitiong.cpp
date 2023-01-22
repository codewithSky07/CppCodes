class Solution {
public:
    // to store the ans.
     vector<vector<string>> ans;

     bool palindrome(string s,int start,int end ){
         while(start<end){
             if(s[start++] != s[end--]){return false;}
         }
         return true;
     }

     void recursion(string s,vector<string>&temp,int index ){

        //  base case 
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }

        // loop and do partition based on if palindrome string from 0 to index.
        for(int i=index;i<s.size();i++){
            // if it is palindrome
            if(palindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                recursion(s,temp,i+1);
                // pop out value in backtracking for new seq if possible.
                temp.pop_back();
            }
        }

     }


    vector<vector<string>> partition(string s) {
       vector<string> temp;
      
        recursion(s,temp,0);
        return ans;
    }
};
