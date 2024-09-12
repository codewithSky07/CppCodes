class Solution {
public:
    void dfs(int i,int j,auto& grid){
        if(i<0 || i>= grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0){
            return;
        }

        // make visited.
        grid[i][j] =0;

        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);

    }
    int countOfIsland(vector<vector<int>>&grid){
        int count =0;
        auto temp = grid; // make copy here itself not in the main func to avoid confution.

        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[0].size();j++){
                if(temp[i][j] == 1){ // make dfs call here.
                    dfs(i,j,temp);
                    count++;
                }
            }
        }

        return count;

    }
    int minDays(vector<vector<int>>& grid) {
        auto temp = grid;
        int numOfIslands = countOfIsland(temp);

        // already seperated.
        if(numOfIslands == 0 || numOfIslands >=2) return 0;
    
        // test for each cell.
        else{
            temp = grid;
            for(int i=0;i<temp.size();i++){
                for(int j=0;j<temp[0].size();j++){
                    if(temp[i][j] == 1){
                        // make it 0 and count island
                        temp[i][j] = 0;
                        int minday =countOfIsland(temp);
                        if(minday>=2 || minday == 0) return 1;
                        temp[i][j] = 1;
                    }
                }
            }
        }

        return 2;
        
    }
};
