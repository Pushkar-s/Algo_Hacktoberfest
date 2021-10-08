class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i<board.size(); i++)
        {
            for(int j = 0; j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                    continue;
                else {
                    int val = board[i][j] - '0' - 1;
                    int k = i/3 * 3 + j/3;
                    if(used1[i][val] or used2[j][val] or used3[k][val])
                        return false;
                    used1[i][val] = used2[j][val] = used3[k][val] = 1;
                }
            }
            
        }
        return true;
    }
};  
