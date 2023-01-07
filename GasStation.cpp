class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
          //greedy problem O(n)
        
        int totalcost = 0;
        int currcost=0;
        int startIndex =0;
        
        
        for(int i=0;i<gas.size();i++)
        {
            // (gas-cost) add in total and currcost.
            
            currcost +=gas[i]-cost[i];
            // if ans exists value net cost should be positive.
            totalcost+=gas[i]-cost[i];
            
            //if currcost is -ve then reintialize startindex.
            if(currcost<0){
                startIndex = i+1;
                currcost=0;
            }
        }

        return totalcost>=0 ? startIndex:-1;
    
    
    }
};
