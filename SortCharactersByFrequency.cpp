class Solution {
public:
    string frequencySort(string s) {
//         map declare.
        unordered_map<char,int>mp;
//         Declare priority queue to get value sorted according to freq.
        priority_queue<pair<int,char>>pq;

//         string to send the ans.
        string ans ="";


        for(char ch:s){
            mp[ch]++;
        }
//         push in priority queue.
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

//         traverse in heap and append char to the string.
        while(!pq.empty()){
            auto temp = pq.top();
            int freq = temp.first;
            char ch = temp.second;

            ans+=string(freq,ch);
            pq.pop();
        }

        return ans;

    }
};
