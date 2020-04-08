#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define inf(i) i-i%3
#define sup(i) i-i%3+3
         
     
int lireSudoku(FILE *fich,int sudoku[9][9])
{int i,j,res;
 int val; 
 for (i=0; i<9; i++) 
   for (j=0; j<9; j++) 
     {
       res=fscanf(fich, "%d",&val);
       if (res==EOF)
         {
           fprintf(stderr,"Fin de ficher atteinte: manque des coefficients\n");
           exit(-1);
         }
       sudoku[i][j]=val;
     }
 return(0);
}

int ecrireSudoku(FILE *fich,int sudoku[9][9])
{int i,j;
 for (i=0; i<9; i++) 
   {
     for (j=0; j<9; j++) 
       {
         fprintf(fich, "%d ",sudoku[i][j]);
       }
     fprintf(fich, "\n");
   }
 return(0);
}


int row[9];

int *getRow(int sudoku[9][9], int ind){

	for(int i = 0; i<9; i++){
		row[i] = sudoku[i][ind];
	}

	return row;
}


int col[9];

int *getCol(int sudoku[9][9], int ind){

	for(int i = 0; i<9; i++){
		col[i] = sudoku[ind][i];
	}

	return col;

}

int reg[9];

int *getReg(int sudoku[9][9], int rowInd, int colInd){

//	fprintf(stdout, "-----\n");
	int ind =0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			reg[ind++] = sudoku[i + rowInd*3][j + colInd*3];
//			fprintf(stdout, "%d : ", ind-1);
//			fprintf(stdout, "%d \n", reg[ind-1]);
		}
	}

	return reg;
}

int mySudokuValide(int sudoku[9][9]){

	for(int i = 0; i < 9; i++){
		int* currentCol = getCol(sudoku, i);
		int* currentRow = getRow(sudoku, i);

		for(int j = 0; j < 9; j++){
			if(currentCol[j]<0 || currentCol[j]>9) return(0);
			if(currentRow[j]<0 || currentRow[j]>9) return(0);

			for(int k = 0; k < 9; k++) {
				if (k != j) {
					if (currentCol[j] == currentCol[k]) return (10);
					if (currentRow[j] == currentRow[k]) return (20);
				}
			}
		}
	}



	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int* currentReg = getReg(sudoku, i, j);

			for(int ii = 0; ii < 3; ii++){
				for(int k = 0; k < 3; k++){
					if(ii != k) {
						if (currentReg[ii] == currentReg[k]) return (30);
					}
				}
			}

		}
	}
	return(1);
}


int sudokuValide(int sudoku[9][9])
{int i,j,k,ii,jj;

	for (i=0; i<9; i++)
		for (j=0; j<9; j++)
		{
			if ((sudoku[i][j]<0)||(sudoku[i][j]>9))
				fprintf(stdout,"coefficient (%d,%d) non valide (%d)\n",i,j,sudoku[i][j]);
			/* ligne */
			if (sudoku[i][j]!=0)
			{
				for (k=0; k<9; k++)
					if (k!=j)
						if (sudoku[i][j]==sudoku[i][k])
						{
							fprintf(stdout,"coefficient (%d,%d) identique à (%d,%d)\n",i,j,i,k);
							return(0);
						}
				/* colone */
				for (k=0; k<9; k++)
					if (k!=i)
						if (sudoku[i][j]==sudoku[k][j])
						{
							fprintf(stdout,"coefficient (%d,%d) identique à (%d,%d)\n",i,j,k,j);
							return(0);
						}
				/*regions*/
				for (ii=inf(i); ii<sup(i); ii++)
					for (jj=inf(j); jj<sup(j); jj++)
						if ((ii!=i)&&(jj!=j))
							if (sudoku[i][j]==sudoku[ii][jj])
							{
								fprintf(stdout,"coefficient (%d,%d) identique à (%d,%d)\n",i,j,ii,jj);
								return(0);
							}
			}
		}
	return(1);
}

int solver(int sudoku[9][9]) {

	int M[9][9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0) {
				int* currentRow = getRow(sudoku, i);
				int* currentCol = getCol(sudoku, j);
				int* currentReg = getReg(sudoku, inf(i), inf(j));

				for (int k = 0; k < 9; k++) {
					if (currentRow != 0) M[i][j][currentRow[k]] = 1;
					if (currentCol != 0) M[i][j][currentCol[k]] = 1;
					if (currentReg != 0) M[i][j][currentReg[k]] = 1;
				}
			}
		}
	}

	while (!(sudokuValide(sudoku))) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				int count = 0;
				int value = 0;
				for (int k = 0; k < 9; k++) {
					if (k == 1) count++;
					if (k == 0) value = k;
				}
				if (count == 8) {
					sudoku[i][j] = value;
				}
			}
		}
	}

	ecrireSudoku(stdout,sudoku);
	return(0);
}