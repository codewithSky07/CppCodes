class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>& paths,vector<int>path,int start,int destination){
       
        path.push_back(start);
        // Base condtion if start == destination.
        if(start == destination){
            paths.push_back(path);
            return;
        }
        // traversal in dfs (adjacency list is already given)
        for(auto x:graph[start]){
            dfs(graph,paths,path,x,destination);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        // 2D vector to store the paths.
        vector<vector<int>> paths;
        // to store the path
        vector<int>path;

        int nodes = graph.size();

        if(nodes == 0) return paths;

        // track paths using dfs traversal
        dfs(graph,paths,path,0,nodes-1);

        return paths;
    }
};
