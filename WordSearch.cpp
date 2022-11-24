class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int count){
//          Base case 
        
        // Complete traversal of word.
        if(count == word.size()){return true;}
        //  Return  cases.      
        if(i<0 || i>=board.size() ||j<0 || j>=board[0].size() || word[count] != board[i][j]){return false;}
        
//         Make it visited. 
        char temp = board[i][j];
        board[i][j] = '*';
//         Make traversal
        
        bool isfound = dfs(board,word,i+1,j,count+1) || dfs(board,word,i-1,j,count+1) ||dfs(board,word,i,j+1,count+1)||dfs(board,word,i,j-1,count+1);
        
//         Backtrack.
        board[i][j] = temp;
        
        return isfound;
        
        
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]  == word[0] && dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;    
    }
};
