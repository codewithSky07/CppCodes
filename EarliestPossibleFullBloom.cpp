class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int,int>>store(n);
        
        // for storing the values.
        for(int i=0;i<n;i++){
            store[i].first = -growTime[i];
            store[i].second = plantTime[i];
        }
        
        // sort function.
        sort(store.begin(),store.end());
        
        int totaltime = 0;
        int currtime =0;
        
        for(int i=0;i<store.size();i++){
            totaltime = max(totaltime,currtime+(store[i].second-store[i].first));
            currtime +=store[i].second; 
        }
        
        return totaltime;
        
        
    }
};
