class Solution {
public:
    
    static bool sorting(pair<int,int>a,pair<int,int>b){
        if(a.first == b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    
        vector<vector<int>> result;
        
        vector<pair<int,int>> store;
        
        for(int i=0;i<buildings.size();i++){
            int height = buildings[i][2];
            int start = buildings[i][0];
            int ending = buildings[i][1];
            
            store.push_back({start,-height});
            store.push_back({ending,height});
        }
        
        // constum sorting.
        sort(store.begin(),store.end(),sorting);
        
        int currentHeight = 0;
        multiset<int>st;
        
        st.insert(0);
        
        for(auto x:store){
            if(x.second<0){
                st.insert(-1*x.second);
                
                if(currentHeight != *st.rbegin()){
                    currentHeight = *st.rbegin();
                    
                    vector<int>temp = {x.first,currentHeight};
                    result.push_back(temp);
                }
                
            }
            else if(x.second>=0){
                auto  it = st.find(x.second);
                st.erase(it);
                
                if(*st.rbegin() != currentHeight){
                    currentHeight = *st.rbegin();
                    
                    vector<int>temp = {x.first,currentHeight};
                    result.push_back(temp);
                }
            }
            
            
        }
        
        return result;
        
        
    }
};
