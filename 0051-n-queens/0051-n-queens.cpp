class Solution {
public:
    // bool isSafe(int col, int row, vector<string> &board, int n)
    // {
    //     int ncol = col, nrow = row;
    //     for(int i = 0; i<col; i++)
    //     {
    //         if(board[row][i]=='Q')
    //             return false;
    //     }
    //     while(col>=0 && row>=0)
    //     {
    //         if(board[row][col]=='Q')
    //             return false;
    //         row--;
    //         col--;
    //     }
    //     col = ncol;
    //     row = nrow;
    //     while(col>=0 && row<n)
    //     {
    //         if(board[row][col]=='Q')
    //             return false;
    //         row++;
    //         col--;
    //     }
    //     return true;
    // }
    void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans, vector<bool> &rowQ, vector<bool> &uppDiag, vector<bool> &lowDiag)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++)
        {
            if(!rowQ[row] && !uppDiag[n+col-row-1] && !lowDiag[row+col])
            {
                board[row][col] = 'Q';
                rowQ[row] = true;
                uppDiag[n+col-row-1] = true;
                lowDiag[row+col] = true;
                solve(col+1,board,n,ans,rowQ,uppDiag,lowDiag);
                board[row][col] = '.';
                rowQ[row] = false;
                uppDiag[n+col-row-1] = false;
                lowDiag[row+col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        vector<bool> rowQ(n, false), uppDiag(2*n-1, false), lowDiag(2*n-1, false);
        solve(0,board,n,ans,rowQ,uppDiag,lowDiag);
        return ans;
    }
};