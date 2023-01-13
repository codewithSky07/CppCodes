class Solution {
    // to store the ans.
    int ans=1;  
    vector<vector<int>>adjlist;

    int dfs(int node,int parent,string& s){
        // to store the max length upto that node including it , so initialize with 1.
        int maxpath=1;
		
		//only take children
        for(auto x : adjlist[node]){
        //   check only for children
            if(x != parent){
            int temp=dfs(x,node,s);
			
			//if node character and its child character is not equal
            if(s[node]!=s[x]){
                // update the ans with maximum value.
                // update the maxpath length to return to its parent.
                ans=max(ans,maxpath+temp);   
                maxpath=max(maxpath,1+temp); 
            }
            }
        
        }
        // return the maxpath for current node.
        return maxpath; 
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        adjlist.resize(n);
		
		//create adjacency list 
        for(int i=1;i<n;i++){
            adjlist[parent[i]].push_back(i);
            adjlist[i].push_back(parent[i]);
        }
		//call dfs.
        dfs(0,-1,s);
        return ans;  
    }
};
