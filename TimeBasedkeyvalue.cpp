class TimeMap {
public:
    map<string,map<int,string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end()){
            auto it = mp[key].lower_bound(timestamp);
            
            if(it->first == timestamp)
                return it->second;
            
            it--;
            if(it->first<timestamp){
                return it->second;
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
