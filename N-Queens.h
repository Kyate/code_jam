class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       for(int i = 0;i<n;i++)
         board.push_back(-1); //initialization for values into -1. 
       backTrack(0,n);
       return result;
    }
 private:
 vector<int>board;
 vector<vector<string>> result;
 void backTrack(int k, int n)
 {
     for(int i = 0;i<n;i++) //for k rows, check all columns. 
     {
         if(place(k,i) == true)
         {
             if(k==(n-1)) 
                save_result(n);
             backTrack(k+1,n);
         }
     }
 }
 
 bool place(int k,int i)
 {
    //check previous rows and cols for placed queens.
    for(int row = 0; row<k;row++)
    {
        int col = board[row]; //placed queens(row,col)
        if(k==row) return false;
        if(i==col) return false;
        if(abs(k-row) == abs(i-col)) return false;
    }
    board[k] = i;
    return true;
 }
 
 void save_result(int n)
 {
     vector<string>ans;
     for(int i = 0; i< n;i++)
     {
         int col = board[i];
         string tmp;
         for(int j = 0;j<n;j++)
         {
             if(j==col)
                tmp.push_back('Q');
            else
                tmp.push_back('.');
         }
         ans.push_back(tmp);
     }
     result.push_back(ans);
 }
 
 
};
