class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int totaltime =0;
        int currmax = neededTime[0];
        
        for(int i=1;i<colors.size();i++){
            
            if(colors[i] == colors[i-1]){
                totaltime += min(neededTime[i],currmax);
                currmax = max(currmax,neededTime[i]);
            }
            else if(colors[i] != colors[i-1]){
                currmax = neededTime[i]; // update for new color seq.
            }
        }
        
        
        return totaltime;
        
    }
};
