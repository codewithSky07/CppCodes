class Solution {
public:
    int mod = 1e9+7;
    
    int HelperforRecursion(int dices,int faces,int target){
        
        //base case
        if(dices==0) return target == 0;
        
        int ans=0;
        for(int i=1;i<=faces;i++){
            ans = ans+ HelperforRecursion(dices-1,faces,target-i);
        }
        
        return ans;
        
    }
    
    int HelperforMemo(int dices,int faces,int target,vector<vector<int>>&dp){
        
               //base case
        if(dices==0) return target == 0;
        
        // already visited or calcualted values.
       if( dp[dices][target] != -1 ) return dp[dices][target];
        
        int ans=0;
        for(int i=1;i<=faces;i++){
            if(target-i>=0)
            ans = (ans+ HelperforMemo(dices-1,faces,target-i,dp))%mod;
        }
        dp[dices][target] = ans;
        
        return ans;
    }
    
    
    
  int HelperForTabular(int dices,int faces,int target){
      vector<vector<int>>dp(dices+1,vector<int>(target+1,0));
      

      
      dp[0][0] = 1;
      
      for(int i=1;i<=dices;i++){
          for(int j = 1;j<=target;j++){
              for(int f=1;f<=faces;f++){
                      if(j-f>=0)
                    dp[i][j] = (dp[i][j]+ dp[i-1][j-f])%mod;
              }
          }
      }
      return dp[dices][target];

  }
    
    
    
    int numRollsToTarget(int n, int k, int target) {
        // return HelperforRecursion(n,k,target);
        
        // memoization. // top down
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return HelperforMemo(n,k,target,dp);
        
        // tabular , bottom up
        return HelperForTabular(n,k,target);
    }
};
