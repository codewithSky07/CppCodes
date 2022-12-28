class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end());

        for(int i=0;i<k;i++){
            int temp = pq.top();
            pq.pop();
            pq.push(temp-(temp/2));
        }

        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }

        return ans;

    }
};
