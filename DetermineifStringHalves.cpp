class Solution {
public:
    bool isvowel(char ch){
        if(ch =='a'|| ch =='e'||ch == 'i'||ch == 'o'|| ch == 'u'|| ch =='A'|| ch =='E'|| ch =='I'||ch == 'O'|| ch =='U')
            return true;
        return false;         
    }
    
    
    bool halvesAreAlike(string s) {
        int left = 0;
        int right = s.size()-1;
        
        int leftCount = 0;
        int rightCount= 0;
        
        while(left<right){
           if (isvowel(s[left++]))leftCount++;
           if (isvowel(s[right--]))rightCount++;
        }
        return leftCount == rightCount;
        
    }
};
