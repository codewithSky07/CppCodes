class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
//         Set initial values as -1.
        vector<int>lossCounter(100001,-1);
        
//         -1 = not played match. 
//          0 =  not lost a single match.
//          1 = lost excatly 1 match.
        
        for(auto& match:matches){
            
            int winner = match[0];
            int loser = match[1];
            
//             if it is winner make it 0 means , identify he won the match.
            if(lossCounter[winner] == -1){lossCounter[winner] = 0;}
            
//             check for players 1. loser.
//             played his first game.
            if(lossCounter[loser] == -1){lossCounter[loser] = 1;}
//             i.e player has already lost once.
            else{lossCounter[loser]++;} 
   
        }
        
//          return ans. 
        vector<vector<int>>ans(2,vector<int>());
        
        for(int i=1;i<100001;i++){
            if(lossCounter[i] == 1){
                ans[1].push_back(i);
            }else if(lossCounter[i] == 0){
                ans[0].push_back(i);
            }
        }
        
        return ans;
        
    }
};
