class Solution {
public:
 bool detectCapitalUse(string word) {
        // count the capital letters present in words.
        int count =0;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])){
                count++;
            }
        }
        if((count == word.size()) || (count == 0) || (count == 1 && isupper(word[0])))
       {   return true; }
        return false;
    }
};
