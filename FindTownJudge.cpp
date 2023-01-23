class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // trust and trustedby.
        vector<pair<int,int>>mp(n+1,{0,0});

        for(int i=0;i<trust.size();i++){
            int person = trust[i][0];
            int trustTo = trust[i][1];

            mp[person].first +=1;
            mp[trustTo].second +=1; 
        }

        for(int i=1;i<=n;i++){
            if(mp[i].first == 0 && mp[i].second == n-1){return i;}
        }

        return -1;

    }
};
