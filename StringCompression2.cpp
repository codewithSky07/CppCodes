class Solution {
public:
    
    int getLength(int count){
        return count == 1 ? 1 : (count<10?2: (count<100 ? 3:4));
    }
    
    
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.size();
        
        int dp[n+1][k+1];
        
        for(int i=n;i>=0;i--){
            for(int j=0;j<=k;j++){
                
                // declare
                
                if(i == n) { dp[n][j] = 0;  continue;}
                
                // case 1 - delete the ith character if possible (j>0)
                dp[i][j] = j>0 ? dp[i+1][j-1]:INT_MAX;
                
                // case 2-  keep the ith index.
                
                // find the index end point
                
                int possible_del = j,count=0;
                for(int end =i;end<n&&possible_del>=0 ;end++){
                    if(s[end] == s[i]){
                        count++;
                        
                        // assumeing the block end here "aaaa"
                        dp[i][j] = min(dp[i][j] , getLength(count)+dp[end+1][possible_del]);
                    }
                    else {
                        // this character should be deleted. to make length min.
                        possible_del--;
                    }
                }
                
                
            }
        }
        
        return dp[0][k];
    }
};
