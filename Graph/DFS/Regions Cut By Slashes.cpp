class Solution {
public:
    void dfs(auto& store,int i,int j){
        if(i<0 || j<0|| i>=store.size()||j>=store.size() || store[i][j] == 1){
            return;
        }

        // make visited.
        store[i][j] = 1;

    // Visit all 4 directions (up, down, left, right)
        dfs(store,i+1,j);
        dfs(store,i-1,j);
        dfs(store,i,j+1);
        dfs(store,i,j-1);
    }
    int regionsBySlashes(vector<string>& grid) {
        // n*n so, rows == coln = n.
        int n = grid.size();

        // Create a 3*n x 3*n grid where each cell is divided into 9 smaller parts
        vector<vector<int>>store(3*n,vector<int>(3*n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                     int actualI = i*3;
                    int actualJ = j*3;
                if(grid[i][j] == '/'){
                    store[actualI][actualJ+2] = 1;// Top-right
                    store[actualI+1][actualJ+1] = 1; // Middle
                    store[actualI+2][actualJ] = 1; // Bottom-left
                }else if(grid[i][j] == '\\'){
                    store[actualI][actualJ] = 1; // Top-left
                    store[actualI+1][actualJ+1] = 1; // Middle
                    store[actualI+2][actualJ+2] = 1; // Bottom-right
                }
            }
        }
         // Now count the number of connected regions using DFS
        int count =0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                    if(store[i][j] == 0){ // Unvisited part, start a DFS
                        count++; 
                        dfs(store,i,j);
                    }
            }
        }

        return count;

    }
};
