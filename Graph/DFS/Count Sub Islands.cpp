class Solution {
public:

    vector<vector<int>>direction = {{0,1},{0,-1},{1,0},{-1,0}};
   
    void dfs(auto& grid1,auto& grid2,int i,int j,bool& res){
        if(i<0 || i>=grid2.size() || j<0 || j>=grid2[0].size() || grid2[i][j] == 0) return;

        // change res.
        if(grid1[i][j] == 0) res = false; 

        // make visited
        grid2[i][j] = 0;

        // traversal
        dfs(grid1,grid2,i+1,j,res);
        dfs(grid1,grid2,i-1,j,res);
        dfs(grid1,grid2,i,j+1,res);
        dfs(grid1,grid2,i,j-1,res);

    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) { 
        int count = 0;

        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j] == 1){
                        // do normal dfs on grid2. if at any point grid2[i][j] == 1 && grid1[i][j] == 0
                        // not possible.
                        bool res = true;
                        dfs(grid1,grid2,i,j,res);
                        if(res == true){
                            count++;
                        }

                }
            }
        }

        return count;
    }
};
