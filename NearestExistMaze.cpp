class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
//        declare rows and column variable.
        int rows = maze.size();
        int columns = maze[0].size();

//         we will perfom bfs as shorter distance node will be traverse first at one level.
//         define queue.
        queue<pair<int,int>>q;
        int steps = 1;

//         all the valid traversal direction.
        vector<vector<int>>direction = {{0,1},{0,-1},{1,0},{-1,0}};
        
//         push the entry to the queue & make it visited. and apply bfs .
        q.push({entrance[0],entrance[1]}); // q.push((x , y))
//         make it visited.
        maze[entrance[0]][entrance[1]] = '+';
        
        while(!q.empty()){
            
//             check the node in that level.
               int l=q.size();
//        for every node in the queue visit all of it's adjacent nodes which are not visited yet
            for(int i=0;i<l;i++)
            {
                auto [x_cord,y_cord]=q.front(); // x and y coordinates.
                q.pop();
                
//                 check in all the 4 directions, non visited nodes.
                				
                for(int k=0;k<4;k++)
                {
                    int x=x_cord+direction[k][0];
                    int y=y_cord+direction[k][1];
                    
//                   if it is invalid move (visited , out of bound.) , continue.
                    if(x<0 || y<0 || x>=rows || y>=columns || maze[x][y]=='+')
                        continue;
//                   if we have reached the exit then current steps are the min steps to reach the exit
                    if(x==0 || y==0 || x==rows-1 || y==columns-1)
                        return steps;
//                   block the cell as we have visited and push in queue.
                    maze[x][y]='+';
                    q.push({x,y});
                }
            }
			//increment the steps. i.e for one circle we did not find exit.
            steps++;

            
            
        }
//         if steps are not found.
        return -1;
        
        
    }
};
