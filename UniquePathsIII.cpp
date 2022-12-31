class Solution {
public:
    int ans = 0;
    int nonObstacle = 1;

    // dfs from the starting position.
   void dfs(int i,int j,vector<vector<int>>&grid,int count){
    //    base condtion.
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() ||grid[i][j] == -1){
        return ;
    }
    if(grid[i][j] == 2){
        // if we got all the nonobstacle cover.
       if(count == nonObstacle){
            ans++;
       }
       return;    
    }

    // make current node visited.
    grid[i][j] = -1;

    // Traversal.
    dfs(i+1,j,grid,count+1);
    dfs(i-1,j,grid,count+1);
    dfs(i,j+1,grid,count+1);
    dfs(i,j-1,grid,count+1);


    // backtracking make it non-visited.
    grid[i][j] = 0;

   }


    int uniquePathsIII(vector<vector<int>>& grid) {
        
        // store the starting position.
        int startX = 0;
        int startY = 0;

        // find the starting location and number of non-obstacle square.
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++){
                // if we got the starting position.
                if(grid[i][j] == 1){startX = i; startY =j;}
                else if(grid[i][j] == 0){nonObstacle++;}
            }
        }

        // call the dfs from the starting position.
        dfs(startX,startY,grid,0);

        return ans;
    }
};
