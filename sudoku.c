#include<stdio.h>
int sudoku[9][9]; //store entire sudoku
void solvesudoku(int,int);

int checkrow(int row,int num);
{
    //checks whether we can put the number(num) in the row(row)
    int column;
    for(column=0;column<9;column++)
    {
        if (sudoku[row][column]==num)

        {
            //if the number is found alredy present 
            return 0;
        }
    }
    //if the number is not found anywhere
    return 1;
}

int checkcolumn(int column, int num)
{
    //checks whether we can put the number(num) in the column(column)
    int row;
    for(row=0;row<9;row++)
    {
        if(sudoku[row][column]==num)
        {
           //if the number is found already present
           return 0;
        }   
    } 
    //if number is not found anywhere 
    return 1;
}

int checkgrid(int row, int column, int num)
{
    //this function checks whether we can put the number(num) in the 3*3 grid or not  
    //we get the starting row and column for the 3*3 grid
    row = (row/3)*3;
    column = (column/3)*3;

    int r,c;
    for(r=0;r<3;r++)
    {
        for(c=0;c<3;c++)
        {
            if(sudoku[row+r][column+c]==num)
            {
                //if the number is found already present 
                return 0;
            }
        } 
    }
     //if the number is not found anywhere 
        return 1;
}

void navigate(int row,int column)
{
    //function to move to the next cell in casee we have filled one cell
    if (column<8)
    {
        solvesudoku(row,column+1);
    }
    else
    {
        solvesudoku( row+1,0);
    }
}

void display()
{
    //the function to display the solved sudoku
    int row,column;
    printf("THE SOLVED SUDOKU\n");
    for(row=0;row<9;row++)
    {
        for (column=0;column<9;column++)
        printf("%d",sudoku[row][column]);
        
        printf("\n");
    }
}

void solvesudoku(int row,int column)
{
    //if the row number is greater than 8 than we have filled all cells hence we have solved the sudoku
     if (row>8)
    display();

    if (sudoku[row][column]!=0)
    {
        //if the value filled at a cell is not zero than 
        navigate();
    }
    else
    {
      //counter to check number from 1 to 9 whether the number can be filled in the cell or not
      int ctr;
      for (ctr=1;ctr<=9;ctr++)
      {
        //we check row,column and the grid
        if((checkrow(row,ctr)==1)&&(checkcolumn(column,ctr)==1)&&(checkgrid(row,column,ctr)==1))
        {
            sudoku[row][column]=ctr;
            navigate(row,column);
        }
      }
      //no valid number was found 
      sudoku[row][column]=0;
    }
}

int main()
{
    int row , column;
    printf("enter the desired sudoku and enter 0 for unknown entries\n");
    for(row=0;row<9;row++)
    {
        for (column=0; column<9; column++)
         {
          scanf("%d",&sudoku[row][column]);
         }    
    }
    // we start solving the sudoku
    solvesudoku(0,0);
    return 0;
}    