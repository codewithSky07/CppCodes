class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
          // declare for storing ans.
vector<int> result(grid[0].size(), 0);

  // loop: for each ball , (col) , traverse the rows.

        for (int col = 0; col < grid[0].size(); col++) {
  // initialize the val of a ball.
            int currentCol = col;

   for (int row = 0; row < grid.size(); row++) {
         //next move of the ball. (which will be next col.)
    int nextColumn = currentCol + grid[row][currentCol];
  // base condition (Blocking condition)
                if (nextColumn < 0 || nextColumn > grid[0].size() - 1 ||grid[row][currentCol] != grid[row][nextColumn]) 
   {
                    result[col] = -1;
                    break;
                }
  // Update the values in result and currentCol.
                result[col] = nextColumn;
                currentCol = nextColumn;
            }
        }
        return result;
    }
};
