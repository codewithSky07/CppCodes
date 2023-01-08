class Solution {
public:
 int maxPoints(vector<vector<int>>& points) {
        int ans = 1;

        for(int i=0;i<points.size()-1;i++){
        // mp of <slope,point> for each point we want new map to declare.
        unordered_map<double,int>mp;
            for(int j=i+1;j<points.size();j++){
                // if x cordinates are same then slope will be infinite as bottom will be 0.
                if(points[i][0] == points[j][0]){mp[1000001]++;}
                else{
                    double slope = (double)(points[j][1]-points[i][1])/(double)(points[i][0]-points[j][0]);
                    // store in map
                    mp[slope]++;
                }
            }
            // now we have slopes for each points store in map.
            // count the maximum points .
            int temp=0;
            for(auto x:mp){
                temp = max(temp,x.second);
            }
            // temp store max points with same slope with respect to point i.
            // store the maximum value in ans.
            // total points in line will be temp+1 as 1 for the ith point also.
            ans = max(ans,temp+1);
        }
        return ans;
    }
};
