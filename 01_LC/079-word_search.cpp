/*
 * Date:2021-05-27 21:31
 * filename :079-word_search.cpp
 *
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size();++i) {
            for ( int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word.at(0)) {
                    if (dfs(board, word, i, j, 0)) 
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (k == word.size()) return true;
        if ( i < 0 || j < 0 || i >= board.size() || j >= board[i].size()) return false;
        if ( word.at(k) != board[i][j]) return false;
        char t = board[i][j];
        board[i][j] = '0';
        bool res = dfs(board, word, i + 1, j, k + 1) ||
                   dfs(board, word, i - 1, j, k + 1) ||
                   dfs(board, word, i, j + 1, k + 1) ||
                   dfs(board, word, i, j - 1, k + 1);
        board[i][j] = t;
        return res;
    }
};
 
 
