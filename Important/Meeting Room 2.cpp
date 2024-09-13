/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // min number of room required . 

        // sort based on start time.
        sort(intervals.begin(),intervals.end(),[&](auto& a, auto& b) {
            return a.start < b.start;  // Sorting by start time
        });

        if(intervals.size() == 0) return 0;

        auto myLambda = [&](auto& a,auto& b){
            return a.end>b.end;
        };


        // sorting according to the minimum end time.
        priority_queue<Interval,vector<Interval>,decltype(myLambda)>pq(myLambda);

        pq.push(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start < pq.top().end){
                pq.push(intervals[i]);
            }else{
                pq.pop();
                pq.push(intervals[i]);
            }
        }

        return pq.size();
        
    }
};
