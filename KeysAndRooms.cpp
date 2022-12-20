class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<int>&visited,int current){
        // make visited.
        visited[current] = 1;

        // traversal.
        for(int i =0;i<rooms[current].size();i++){
            // if not visited call dfs.
            if(!visited[rooms[current][i]]){
                dfs(rooms,visited,rooms[current][i]);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);

        dfs(rooms,visited,0);

        for(int i=0;i<n;i++){
            if(visited[i] == 0)
            return false;
        }
        return true;
    }
};
