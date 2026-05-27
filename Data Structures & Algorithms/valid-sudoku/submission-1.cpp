class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,bool>row[9],col[9];
        unordered_map<int,bool>box[9];
        for(int i =0 ;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    int box_no = (i / 3) * 3 + (j / 3);
                    int val = board[i][j] - '0';
                    if(box[box_no][val] || row[i][val] || col[j][val])
                    {
                        return false;
                    }
                    box[box_no][val] = true;
                    row[i][val] = true;
                    col[j][val] = true;
                }
            }
        }
        return true;
    }
};
