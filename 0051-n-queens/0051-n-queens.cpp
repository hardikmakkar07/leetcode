class Solution {
public:
    bool isSafe(int col, int row, vector<string> &board, int n)
    {
        int ncol = col, nrow = row;
        for(int i = 0; i<col; i++)
        {
            if(board[row][i]=='Q')
                return false;
        }
        while(col>=0 && row>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        col = ncol;
        row = nrow;
        while(col>=0 && row<n)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++)
        {
            if(isSafe(col,row,board,n))
            {
                board[row][col] = 'Q';
                solve(col+1,board,n,ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        solve(0,board,n,ans);
        return ans;
    }
};