class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        //a-z
        
//         for(int i=0;i<26;i++){
//             // a,b,c
//             char currChar = 'a'+i;
            
//             if(sentence.find(currChar) == string::npos){
//                 return false;
//             }
            
//         }
//         return true;
        
        // unorder_set.size() == 26..
        
        unordered_set<char>seen(sentence.begin(),sentence.end());
        
        return seen.size() == 26;
        
        
        
    }
};
