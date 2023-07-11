#include<bits/stdc++.h>
using namespace std;


bool is_safe(vector<vector<char>> board,int r,int c){
    // row
    for(int i=0;i<r;i++){
        if(board[i][c] == 'Q'){
            return false;
        }
    }
    //left diagonal
    for(int i=r,j=c;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //right diagonal
    for(int i=r,j=c;i>=0 && j<board.size();i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}


void n_queens(vector<vector<char>> &board,int r){

    if(r==board.size()){
        for(int i=0;i<board.size();i++){ // printing if reached to the end
            for(int j=0;j<board.size();j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }


    for(int i=0;i<board.size();i++){// traversing through the columns...
//starting at 0 and to the end placing the queen at each column and checking for all the combinations
        if(is_safe(board,r,i)){
            board[r][i] = 'Q';
            n_queens(board,r+1);
            board[r][i] = '+';
        }
    }
}


int main(){
    int n;
    cin>>n;

    vector<vector<char>> board(n, vector<char>(n, '+'));
    n_queens(board,0);
}