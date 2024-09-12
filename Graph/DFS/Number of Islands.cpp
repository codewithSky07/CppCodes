class Solution {
public:
    vector<vector<int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i,int j,auto&grid){
        // base case
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0'){ return; }
        
        // visited
        grid[i][j] = '0';

        // traversal
        for(auto dir:directions){
            int x = i+dir[0];
            int y = j+dir[1];
            dfs(x,y,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }

        return count;
    }
};
