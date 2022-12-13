class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 1) return *min_element(matrix[0].begin(),matrix[0].end());
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0){
                    matrix[i][j] = matrix[i][j];
                }else if(i>0){
                    if(j == 0){
                        matrix[i][j] = matrix[i][j]+min(matrix[i-1][j],matrix[i-1][j+1]);
                        
                    }else if(j == m-1){
                        matrix[i][j] = matrix[i][j]+min(matrix[i-1][j],matrix[i-1][j-1]);
                    }else{
                        matrix[i][j] = matrix[i][j]+min(matrix[i-1][j],min(matrix[i-1][j+1],matrix[i-1][j-1]));
                    }
                }
            }
        }
        
        return *min_element(matrix[n-1].begin(),matrix[n-1].end());
        
        return 0;
    }
};
