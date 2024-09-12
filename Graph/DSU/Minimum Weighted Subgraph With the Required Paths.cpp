class Solution {
    using ll = long long;
    const long long INF = 1e15; 

public:
    void dykstra(auto& adj,auto& res,ll src){

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

        pq.push({0,src});

        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            ll u = curr.second;
            ll d = curr.first;

            if (d > res[u]) continue; // Skip outdated paths

            for(auto&v:adj[u]){
                ll dis = v.second;
                ll node = v.first;

                if(d+dis<res[node]){
                    res[node] = d+dis;
                    pq.push({res[node],node});
                }
            }
        }
    }


    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        unordered_map<int,vector<pair<ll,ll>>>adj;
        unordered_map<int,vector<pair<ll,ll>>>revadj;

        for(auto &x:edges){
            ll u = x[0];
            ll v = x[1];
            ll wt = x[2];

            adj[u].push_back({v,wt});
            revadj[v].push_back({u,wt});
        }

        // make traversal.
        vector<ll>des1(n,INF); des1[src1]= 0;
        vector<ll>des2(n,INF); des2[src2]= 0;
        vector<ll>des3(n,INF); des3[dest]= 0;


        // Source 1, Source 2, aur destination ke liye shortest path find karo
        dykstra(adj,des1,src1);
        dykstra(adj,des2,src2);
        dykstra(revadj,des3,dest); // dest se sab tak (reverse graph)

         // Answer initialize karo INF se
        ll ans = INF;
        for(int i=0;i<n;i++){
            // Har node ke liye check karo ki kya wo reachable hai teeno sources se
            if(des1[i] != INF && des2[i] != INF && des3[i] != INF){
                ans = min(ans, des1[i]+des2[i]+des3[i]); // Teeno distances ka sum karo
            }
        }
          // Agar koi valid path mila, to answer return karo, otherwise -1
        return ans == INF ? -1 : ans;

    }
};
