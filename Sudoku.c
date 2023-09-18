#include <stdio.h>
#include <stdlib.h>

int row_check(int sudoku[9][9]);

int column_check(int sudoku[9][9]);

int square_check(int sudoku[9][9]);

int main()
{
    int sudoku[9][9];

    FILE *fptr;
    fptr = fopen("sudoku_correct.txt", "r");

    if (fptr == NULL)
    {
        printf("File did not opened correctly!\n");
        exit(4);
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            fscanf(fptr, "%d", &sudoku[i][j]);
        }
    }

    fclose(fptr);
     
    int check1 = row_check(sudoku);
    int check2 = column_check(sudoku);
    int check3 = square_check(sudoku);
    
    if (check1 + check2 + check3 == 0)
    {
        printf("Valid Solution\n");
    }
    else
    {
        printf("Invalid Solution\n");
    }
     
    return 0;
}

int row_check(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int stored = sudoku[i][j];
        
            for (int k = j + 1; k < 9; k++)
            {
                int compared = sudoku[i][k];

                if (stored == compared)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int column_check(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int stored = sudoku[j][i];
        
            for (int k = j + 1; k < 9; k++)
            {
                int compared = sudoku[k][i];
                if (stored == compared)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int square_check(int sudoku[9][9])
{
    for(int i = 0; i < 9; i+=3)     //square row
    {
        int lower_row = i;
        int upper_row = i + 3;

        for(int j = 0; j < 9; j +=3)    //square column
        {
            int lower_column = j;
            int upper_column = j + 3;
            
            for(int a = lower_row; a < upper_row; a++)      //stored row
            {
                for(int b = lower_column; b < upper_column; b++)       //stored column
                {
                    int count = 0;

                    int stored = sudoku[a][b];

                    for(int c = lower_row; c < upper_row; c++)      //compared row
                    {
                        for(int d = lower_column; d < upper_column; d++)    //compared column
                        {
                            int compared = sudoku[c][d];

                            if(stored == compared)
                            {
                                count ++;
                            }

                            if(count == 2)
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}