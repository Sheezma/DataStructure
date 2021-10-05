#include <stdio.h>
#define ROWS 4
#define COLS 4
void findSparseMatrix(int matrix[ROWS][COLS]);
int main(){
int matrix[ROWS][COLS];
 for(int i = 0; i < ROWS; i++){
   for(int j = 0; j < COLS; j++){
    // matrix[i][j] = i * j;
    matrix[i][j] = 0;
         }
  }
 findSparseMatrix(matrix);
  return 0;
}

void findSparseMatrix(int matrix[ROWS][COLS]){
 int sparse_counter = 0;
  for(int i = 0; i < ROWS; i++){
   for(int j = 0; j < COLS; j++){
    if (matrix[i][j] == 0){
     ++sparse_counter;
         
     }
      }
    }
  if (sparse_counter > ((ROWS * COLS )/ 2))
   printf("The given matrix is sparse \n");
  else
   printf("The given matrix is not a Sparse Matrix \n"); 
  printf("There are %d number of zeros. \n", sparse_counter);
}
