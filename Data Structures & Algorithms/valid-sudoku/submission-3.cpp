class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>rnum(9,vector<int>(10,0));
        vector<vector<int>>cnum(9,vector<int>(10,0));
        vector<vector<int>>bnum(9,vector<int>(10,0));
        for(int i =0 ;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    int r = i;
                    int c = j;
                    int b = (i/3) * 3 + (j/3);
                    int v = board[i][j] - '0';
                    if(rnum[r][v] == 1 ||cnum[c][v] == 1 || bnum[b][v] == 1)
                    {
                        return false;
                    }
                    rnum[r][v] = 1 ;
                    cnum[c][v] = 1 ; 
                    bnum[b][v] = 1;
                }
            }
        }
        return true;
    }
};
