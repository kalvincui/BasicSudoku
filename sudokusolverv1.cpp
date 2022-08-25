#include <iostream>
 
using namespace std;
 
void print(int board[9][9]){
  for (int i = 0; i<9; i++){
    for (int j = 0; j<9; j++){
      cout << board[i][j] << " ";
      if (j == 2 || j == 5){
        cout << "|" << " ";
      }
    }
    cout << endl;
    if (i == 2 || i==5){
      cout << "---------------------" << endl;
    }
  }
}
 
bool check (int board[9][9], int row, int col){
  //check row
  for (int i =0; i<9; i++){
    if (i == col){
      continue;
    }else {
      if (board[row][i] == board[row][col]){
        return false;
      }
    }
  }
  //check col
  for (int i =0; i<9; i++){
    if (i == row){
      continue;
    }else {
      if (board[i][col] == board[row][col]){
        return false;
      }
    }
  }
 
  //check box
  int rowindex;
  int colindex;
  if (row<3){
    rowindex = 0;
  }else if (row<6){
    rowindex = 3;
  }else {
    rowindex = 6;
  }
  if (col<3){
    colindex = 0;
  }else if (col<6){
    colindex = 3;
  }else{
    colindex = 6;
  }
  for (int i = rowindex; i<rowindex+3; i++){
    for (int j = colindex; j<colindex+3; j++){
      if (i== row && j==col){
        continue;
      }else {
        if (board[i][j] == board[row][col]){
          return false;
        }
      }
    }
  }
 
  return true;
}

bool isValid (int board[9][9]){
  for (int i = 0; i<9; i++){
    for (int j = 0; j<9; j++){
      if (board[i][j] == 0){
        continue;
      }else {
        if (!check(board,i,j)){
          return false;
        }
      }
    }
  }
  return true;
}


bool solve(int board[9][9], int row, int col){
    if (row == 8 && col == 9){
      return true;
    }
    if (col == 9) {
        row++;
        col = 0;
    }
    if (board[row][col] ==0){
      for (int num = 1; num <= 9; num++){
        board[row][col] = num;
        if (isValid(board)){
          if (solve(board, row, col + 1)){
            return true;
          }
        }
      board[row][col] = 0;
      }
    }else {
      return solve (board, row, col+1);
    }
    return false;
}
 
int main(){
  int board[9][9]={0,0,7   ,0,0,0    ,4,0,6,
                8,0,0   ,4,0,0    ,1,7,0,
                 0,0,0   ,3,0,0    ,9,0,5,
                 
                 0,0,0   ,7,0,5    ,0,0,8,
                 0,0,0   ,0,0,0    ,0,0,0,
                 4,0,0   ,2,0,8    ,0,0,0,
                 
                 7,0,4   ,0,0,3    ,0,0,0,
                 0,5,2   ,0,0,1    ,0,0,9,
                 1,0,8   ,0,0,0    ,6,0,0  
  };
  if (solve(board, 0, 0)){
    print(board);
  }else{
    cout << "no solution  exists " << endl;
  }
  return 0;
}
