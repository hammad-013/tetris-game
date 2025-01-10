#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

void gotoRowCol(int rpos, int cpos)
{
    int xpos = cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}

void sleep(int m)
{
    for (int j = 0; j < m * 21000; j++)
    {
    }
}
void fillBoard(int rows, char arr[][20], char ch)
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i == 29)
            {
                arr[i][j] = ch;
            }
            else
            {
                arr[i][j] = '-';
            }
        }
    }
}

void printBoard(int rows, char arr[][20])
{
    for (int i = 0; i < rows; i++)
    {
        cout << "< ! ";
        for (int j = 0; j < 20; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << " ! >" << endl;
    }
    cout << "< ! ";
    for (int k = 0; k < 20; k++)
    {
        cout << "= ";
    }
    cout << " ! >" << endl;
}

void shapeRotation(char shape[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            char temp = shape[i][j];
            shape[i][j] = shape[j][i];
            shape[j][i] = temp;
        }
    }
}
void blockMovement(int height, char boardArr[][20], char ch, char shape[][4], int firstElem, int lastElem, int srow, int scol, int shapeNum, bool &Rotate)
{
    int currentRow = 0;
    while (true)
    {
        sleep(8000);
        // int movement = getch();
        // if (movement == 80)
        //{

        for (int i = 0; i < srow; i++)
        {
            for (int j = 0; j < scol; j++)
            {
                if (boardArr[currentRow][firstElem] != ch)
                {
                    boardArr[currentRow][firstElem] = shape[i][j];
                }
                firstElem++;
            }
            firstElem = 8;
            currentRow++;
        }
        currentRow -= 3;

        gotoRowCol(0, 0);
        printBoard(height, boardArr);

        for (int i = 0; i < srow; i++)
        {
            for (int j = 0; j < scol; j++)
            {
                boardArr[currentRow - 1][firstElem] = '-';
                if (shapeNum == 2)
                {
                    boardArr[currentRow][firstElem] = '-';
                }
                if (Rotate == 1)
                {
                    boardArr[currentRow + 1][firstElem] = '-';
                }
                firstElem++;
            }
            firstElem = 8;
        }
        if (kbhit())
        {
            int key = getch();
            if (key == 72 || key == 80)
            {
                shapeRotation(shape, srow, scol);
                if (Rotate == 0)
                {
                    Rotate = 1;
                }
                else
                {
                    Rotate = 0;
                }
            }
        }
        /* int nextLine;
         if(Rotate=0){
              nextLine = currentRow+4;
         }else if(Rotate=1){
              nextLine = currentRow;
         }*/

        if (shapeNum == 2 && Rotate == 1)
        {
            currentRow += 2;
        }
        else if (shapeNum == 2 && Rotate == 0)
        {
            currentRow += 1;
        }

        if (boardArr[currentRow][firstElem] == ch || boardArr[currentRow][firstElem + 1] == ch || boardArr[currentRow][firstElem + 2] == ch || boardArr[currentRow][firstElem + 3] == ch)
        {
            break;
        }
        else if (shapeNum == 2 && Rotate == 1)
        {
            currentRow -= 2;
        }
        else if (shapeNum == 2 && Rotate == 0)
        {
            currentRow -= 1;
        }
    }
    //}
}

int main()
{
    int height = 30;
    char boardArr[height][20];
    char blockElement = 219;

    char Line[4][4] = {{blockElement, blockElement, blockElement, blockElement},
                       {'-', '-', '-', '-'},
                       {'-', '-', '-', '-'},
                       {'-', '-', '-', '-'}};
    char Zed[4][4] = {{blockElement, blockElement, '-', '-'},
                      {'-', blockElement, blockElement, '-'},
                      {'-', '-', '-', '-'},
                      {'-', '-', '-', '-'}};

    int shapeRows = 4, shapeCols = 4;
    int shapeNum = 2;
    bool shapeRotate = 0;

    /*  for (int i = 0; i < shapeRows; i++){
          for (int j = 0; j < shapeCols; j++){
              cout<<Zed[i][j]<<" ";
          }
          cout<<endl;
      }*/

    fillBoard(height, boardArr, blockElement);
    printBoard(height, boardArr);
    blockMovement(height, boardArr, blockElement, Zed, 8, 11, shapeRows, shapeCols, shapeNum, shapeRotate);

    return 0;
}

/*
void blockMovement(char board[][20],char shape1[1][4],int rows,int &row){
   // int neww=0;
    for (int l = 0; l < rows; l++)
    {

        //int row = l;

        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                board[row][j] = shape1[i][j];
               //neww++;
            }
            row++;
        }
   // neww-=4;

        gotoRowCol(0,0);
        printBoard(rows,board);

        row = l;

        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                board[row][j] = '-';
                //neww++;
            }
            row++;

        }
        //neww-=4;



    if(board[row][0]== char(219) || board[row][1]== char(219) || board[row][2]== char(219) || board[row][3]== char(219)){
            break;
    }
   /*
int movement = getch();
        if(movement==77){
        row--;
        for (int i = 0; i < 1; i++)
        {
            //for (int j = 0; j < 4; j++)
            //{
                board[row][neww] = '-';
                board[row][neww+4] = char(219);
          //  }
           row++;
            neww++;
        }

    }

    }
}




int main()
{
    int rows=30;
    int blockRow = 0;
    int loopBreak;
    char board[rows][20];
    fillBoard(rows,board);
    printBoard(rows,board);

    char shape1[1][4] = {{char(219), char(219), char(219), char(219)}};
    char shape2[2][3] = {{char(219), char(219), '-'},
                         {'-', char(219), char(219)}};
    int shapeChoice = 1;

if(shapeChoice==1){
    loopBreak = 1;
}else if(shapeChoice==2){
    loopBreak = 2;
}
    do{
        blockMovement(board,shape1,rows,blockRow);
        blockRow--;
    }while(blockRow!=loopBreak-1);



    return 0;
}
*/
