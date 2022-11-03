class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        // store the count values for each string.
        vector<vector<int>>counter(26,vector<int>(26,0));

        int ans =0;
        // add 4 to ans if reverse is present in words.
        // i.e counter values are present.
        for(auto x:words){
            int first = x[0]-'a';
            int second = x[1]-'a';

            // if reverse is present "la" and "al" is present in words vector.
            // check through
            if(counter[second][first]){
                ans+=4;
                counter[second][first]--;
            }
            // first time occuring in the words string.
            else{
                counter[first][second]++;
            }
        }


        // add 2 if both letter are same
        for(int i=0;i<26;i++){
            if(counter[i][i]){
                ans+=2;
                break;
            }
        }

        return ans;




    }
};
