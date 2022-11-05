class Solution {
    struct TrieNode {
        TrieNode *children[26];
        string word;

        TrieNode() : word("") {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = buildTrie(words);
        
        vector<string> result;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    // Inserts a word into the trie. 
    TrieNode *buildTrie(vector<string> &words) {
        //create trie.
        TrieNode *root = new TrieNode();
        
        for (int j = 0; j < words.size(); j++) {
            string word = words[j];
            TrieNode *curr = root;
            
            for (int i = 0; i < word.length(); i++) {
                char c = word[i] - 'a';
                if (curr->children[c] == nullptr) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) {
        char c = board[i][j];
        
        // base case.
        if (c == '#' || !p->children[c - 'a']) return;
        
      
        
        // append the child.
        p = p->children[c - 'a'];
        
        // if valid word. add to result. (we got our word.)
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = "";
        }
 
        // make it visited.
        board[i][j] = '#';
        
        // travel in valid direction only. 
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        
        // backtrack the value.
        board[i][j] = c;
    
    }
};
