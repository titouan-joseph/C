int lireSudoku(FILE *fich,int sudoku[9][9]);
int ecrireSudoku(FILE *fich,int sudoku[9][9]);
int sudokuValide(int sudoku[9][9]);
int mySudokuValide(int sudoku[9][9]);
int getRow(int sudoku[9][9], int ind);
int getCol(int sudoku[9][9], int ind);
int getReg(int sudoku[9][9], int rowInd, int colInd);
int solver(int sudoku[9][9]);
