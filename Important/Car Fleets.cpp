class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // pair<dis,time>
        vector<pair<double,double>>store;

        for(int i=0;i<position.size();i++){
                double dis = (double) target-position[i] ;
                double time = (double) dis/speed[i];
                store.push_back({dis,time});
        }

        // sort the store array according to dis. smaller first. because they reach first . Crossing one need to have smaller time then there to reach target.

        sort(store.begin(),store.end(),[&](auto &a,auto &b){
            int disA = a.first;
            int disB = b.first;
            return a.first < b.first;
        });


        // step 3
        int count = 1;
        double currFleetTime = store[0].second;

        for(int i=1;i<store.size();i++){
            double presentCarTime = store[i].second;
            if(currFleetTime >= presentCarTime) // means it will reach faster than fleet , so it will be in the currFleet itself hence no of fleet remain same. else there will be separate fleet for presentCar.
                continue;
            else{
                count++;
                currFleetTime = presentCarTime;  // as this car will be in new fleet and other cars will check , if they can join or not. 
            }
        }
        return count;
    }
};
