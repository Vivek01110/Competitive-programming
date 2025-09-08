#include <iostream>
#include <vector>

using namespace std;


bool isSafe(vector<int>& board, int row, int col) {
   
    for (int i = 0; i < row; i++) { 
        if (board[i] == col || abs(board[i] - col) == row - i) {
            return false;
        }
    }
    return true;
}


void solveNQueens(vector<int> board, int row, int n, vector<vector<int>>& solutions) {
   
        if(row == n){
            solutions.push_back(board);
            return;
        }
       
        for (int i = 0; i < n; i++) {
            if(isSafe(board , row , i)){
                board.push_back(i);
                solveNQueens(board,row + 1 , n ,  solutions);
                board.pop_back();
            }
        }
    
}

void print_board(vector<vector<int>> solutions){
    
    for(int i = 0; i < solutions.size(); i++){
        for(int j = 0; j < solutions[i].size(); j++){
            cout << solutions[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<vector<int>>solutions;
        solveNQueens({} , 0,n,solutions);
        cout << solutions.size() << endl;
        print_board(solutions);
        cout << endl;
    }
}

