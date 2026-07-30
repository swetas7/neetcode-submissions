class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i) {
        // Base case: matched all characters
        if (i == word.length()) return true;

        // Boundary checks & character match check (Early Return/Pruning)
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[i]) {
            return false;
        }

        // Save original char & mark as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions (Up, Down, Left, Right)
        bool found = dfs(board, word, r + 1, c, i + 1) ||
                     dfs(board, word, r - 1, c, i + 1) ||
                     dfs(board, word, r, c + 1, i + 1) ||
                     dfs(board, word, r, c - 1, i + 1);

        // Backtrack: restore cell value
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // Start DFS if the first character matches
                if (board[r][c] == word[0] && dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};