class Solution {
public:
    string reverseWords(string str) {
        stringstream s(str);
        string word;

        // to store words.
        vector<string>temp;
        // to store the ans.
        string ans="";

        while(s>>word){
            temp.push_back(word);
        }
        //now store the words in reverse order and add the extra space at the end of eaach word. except the first one.

        for(int i=temp.size()-1;i>=0;i--){
            if(i!=0)
            ans+=temp[i]+" ";
            else
                ans+=temp[i];

        }
        return ans;
    }
};
