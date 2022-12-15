class Solution {
public:
 int longestCommonSubsequence(string s, string t) {

        int n = s.size();
        int m = t.size();

        int dp[n+1][m+1];


        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                //if sequence as same
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};
