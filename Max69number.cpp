class Solution {
public:
    int maximum69Number (int num) {
        // convert int to string..
        string temp = to_string(num);
        
        for(auto &ch:temp){
            if(ch == '6'){ch = '9'; break;}
        }
        
        return stoi(temp);
        
    }
};
