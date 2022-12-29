typedef pair<int,int> P;
typedef long long ll;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
    //  to store the ans.
    vector<int>ans;

    // min heap
    priority_queue<P,vector<P>,greater<>> pq;

    // insert index in tasks.
    int n = tasks.size();
    for(int i=0;i<n;i++){
        tasks[i].push_back(i);
    }

    // sort according to enqueue time
    sort(tasks.begin(),tasks.end());

    // Traverse the tasks.
    int i = 0;
    ll currentTime = 0;
    while(i<n || !pq.empty()){
        // if pq is empty no task is there , insert one task so time will shift to that task 's enqueue time.
        if(pq.empty()){
           currentTime = max(currentTime,(ll)tasks[i][0]);
        }

        // while i<n , push all the task which are avaiable.
        while(i<n && tasks[i][0]<=currentTime){
            pq.emplace(tasks[i][1],tasks[i][2]);
            i++;
        }

        //  now take out the first job. among them.
         auto[processingTime,index] = pq.top();
         pq.pop();
        //  update the currentTime with processing time for job.
        currentTime += processingTime;
        ans.push_back(index);

    }
    return ans;
    }
};
