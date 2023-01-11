class Solution {
public:
    vector<vector<int>>adjlist;
    
    int dfs(vector<bool>& hasApple,int currentNode,int parent,int dis){
        
        int disFromChildren = 0;
        int disFromRoot = 0;

        for(auto x:adjlist[currentNode]){
            // check only for children if they have apple present or not.
            if(x != parent){
                disFromRoot = dfs(hasApple,x,currentNode,dis+1);
                // if disfromroot != 0 means children have apple . 
                // so calculate the dis from the "x" i.e current node to the children.
                if(disFromRoot != 0)
                disFromChildren += disFromRoot-dis; 
            }
         }
        //  if no children left or not have any children return the total distance for that subtree.
        // (i.e disfromChildren + it own distance from root node (dis))
            return disFromChildren || hasApple[currentNode] ? disFromChildren + dis:0;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        adjlist.resize(n);
        
        for(auto x:edges){
            adjlist[x[0]].push_back(x[1]);
            adjlist[x[1]].push_back(x[0]);
        }
        // current node =0 , parent node =-1,distance or level from root.
        return dfs(hasApple,0,-1,0)*2;

    }
};
