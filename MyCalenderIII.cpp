class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
     
        mp[start]++;
        mp[end]--;
        
        int curr = 0;
        int ans = INT_MIN;
        for(auto x:mp){
            curr+=x.second;
            ans = max(curr,ans);
        }
        return ans;
    }
};
