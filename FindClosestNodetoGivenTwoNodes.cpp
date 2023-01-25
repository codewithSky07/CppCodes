class Solution {
public:
   
    void dfs(vector<int>& edges,int node,vector<int>& dist,vector<int>& visited,int distance){

        // base condition. (already visited or cannot move forward.)
        if(node == -1 || visited[node] == 1 ){return ;}
        
        // make current node visited.
        visited[node] = 1;
        dist[node] = distance;
        // call dfs for other node.
        dfs(edges,edges[node],dist,visited,distance+1);

    }


    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

       vector<int>dist1(n,-1);
       vector<int>dist2(n,-1);

        vector<int>visited(n,0);
        // dfs for 1 node.
        dfs(edges,node1,dist1,visited,0);
        
        // dfs for 2 node.
        vector<int>visited2(n,0);
        dfs(edges,node2,dist2,visited2,0);

        // we have both distance vector filled.

        int ans = -1;
        int value = n;

        for(int i=0;i<n;i++){
            // if they are reachable .
            if(dist1[i] != -1 && dist2[i] != -1){
               if(max(dist1[i] , dist2[i]) < value)
            {
                value = max(dist1[i] , dist2[i]);
                ans = i;
            }
            }
        }

        return ans;

    }
};
