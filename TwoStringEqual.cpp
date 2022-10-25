class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s1 = "";
        string s2="";
        
        for(auto x:word1){
            s1+=x;
        }
        
        for(auto x:word2){
            s2+=x;
        }
        
        return s1.compare(s2) == 0;
        
        
    }
};
