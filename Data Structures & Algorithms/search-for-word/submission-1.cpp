class Solution {
public:

    bool inrange(int x, int y, vector<vector<char>>& board) {
        return x >= 0 && y >= 0 &&
               x < board.size() &&
               y < board[0].size();
    }

    bool solve(int i, int j, int idx,
               vector<vector<char>>& board,
               string& word) {

        if (board[i][j] != word[idx]) {
            return false;
        }

        if (idx == word.length() - 1) {
            return true;
        }

        char original = board[i][j];
        board[i][j] = '#';

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {

            int nx = i + dx[k];
            int ny = j + dy[k];

            if (inrange(nx, ny, board) &&
                board[nx][ny] != '#') {

                if (solve(nx, ny, idx + 1, board, word)) {
                    return true;
                }
            }
        }

        board[i][j] = original;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {

                    if (solve(i, j, 0, board, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};