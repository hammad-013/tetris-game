#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

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
void fillBoard(int rows, char arr[][30], char ch)
{
    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i == 34 || j == 0 || j == 29)
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

void printBoard(int rows, char arr[][30])
{
    for (int i = 0; i < rows; i++)
    {
        cout << "< ! ";
        for (int j = 0; j < 30; j++)
        {
            cout << arr[i][j] << "";
        }
        cout << " ! >" << endl;
    }
    cout << "< ! ";
    for (int k = 0; k < 30; k++)
    {
        cout << "=";
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
    // reverse rows
    for (int i = 0; i < row; i++)
    {
        int start = 0, endd = col - 1;
        while (start < endd)
        {
            int temp = shape[i][start];
            shape[i][start] = shape[i][endd];
            shape[i][endd] = temp;
            start++;
            endd--;
        }
    }
}

bool Collision(int breakRow, int shapeNum, int Rotate, int &firstElem, int &lastElem, char boardArr[][30], char ch)
{

   if((shapeNum == 1 && Rotate == 1)|| (shapeNum == 1 && Rotate == 2)||(shapeNum == 1 && Rotate == 3)||(shapeNum == 2 && Rotate == 2)||(shapeNum == 2 && Rotate == 3)||(shapeNum == 3 && Rotate == 1)||(shapeNum == 3 && Rotate == 2)||(shapeNum == 5 && Rotate == 2)||(shapeNum == 5 && Rotate == 3)||(shapeNum == 6 && Rotate == 1)||(shapeNum == 6 && Rotate == 2)||(shapeNum == 7 && Rotate == 2)||(shapeNum == 7 && Rotate == 3)){
        breakRow += 3;
    }
    else if((shapeNum == 2 && Rotate == 0)||(shapeNum == 3 && Rotate == 0)||(shapeNum == 4)||(shapeNum == 5 && Rotate == 1)||(shapeNum == 6 && Rotate == 3)||(shapeNum == 7 && Rotate == 0)){
        breakRow += 1;
    }
    else if((shapeNum == 2 && Rotate == 1)||(shapeNum == 3 && Rotate == 3)||(shapeNum == 5 && Rotate == 0)||(shapeNum == 6 && Rotate == 0)||(shapeNum == 7 && Rotate == 1)){
        breakRow += 2;
    }

     if(Rotate==0){
        if (shapeNum == 1 )
    {
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 2 )
    {
        if (boardArr[breakRow - 1][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 3 )
    {
        if (boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow - 1][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
     else if (shapeNum == 4)
    {
        if (boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 5 )
    {
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 6 )
    {
        if (boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
     else if (shapeNum == 7 )
    {
        if (boardArr[breakRow - 1][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow - 1][firstElem + 2] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    }
    else if(Rotate==1){
        if (shapeNum == 1)
    {
        if (boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 2)
    {
        if (boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow - 1][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 3)
    {
        if (boardArr[breakRow - 1][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 5)
    {
        if (boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow - 1][firstElem + 2] == ch || boardArr[breakRow - 1][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 6)
    {
        if (boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 7)
    {
        if (boardArr[breakRow - 1][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    }
    else if(Rotate==2){
        if (shapeNum == 1)
    {
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 2)
    {
        if (boardArr[breakRow - 1][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 3)
    {
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow - 1][firstElem + 2] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 5)
    {
        if (boardArr[breakRow - 2][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 6)
    {
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow - 2][firstElem + 1] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 7)
    {
        if (boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    }
    else if(Rotate==3){
        if (shapeNum == 1)
    {
        if (boardArr[breakRow][firstElem] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 2)
    {
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow - 1][firstElem + 1] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 3)
    {
        if (boardArr[breakRow - 1][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
     else if (shapeNum == 5)
    {
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 6)
    {
        if (boardArr[breakRow - 1][firstElem] == ch || boardArr[breakRow - 1][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (shapeNum == 7)
    {
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow - 1][firstElem + 1] == ch)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    }
}
void erasingShapes(int shapeNum, int Rotate, char boardArr[][30], int removeRow, int removeCol)
{
     if(Rotate==0){
        if (shapeNum == 1 )
    {
        for (int i = 0; i < 4; i++)
        {
            boardArr[removeRow - 1][removeCol + i] = '-';
        }
    }
    else if (shapeNum == 2 )
    {
        removeRow--;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeRow++;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
    }
    else if (shapeNum == 3 )
    {
        removeCol += 2;
        removeRow--;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeCol -= 1;
        removeRow++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
    }
    else if (shapeNum == 4)
    {
        removeRow--;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeRow++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
    }
    else if (shapeNum == 5 )
    {
        removeRow--;
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
        removeRow += 2;
        removeCol++;
        boardArr[removeRow][removeCol] = '-';
    }
    else if (shapeNum == 6 )
    {
        removeCol += 3;
        removeRow--;
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
        removeCol -= 1;
        removeRow += 2;
        boardArr[removeRow][removeCol] = '-';
    }
     else if (shapeNum == 7 )
    {
        removeRow--;
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeCol += 1;
        removeRow++;
        boardArr[removeRow][removeCol] = '-';
    }
    }
    else if(Rotate==1){
         if (shapeNum == 1 )
    {
        removeRow--;
        removeCol += 3;
        for (int i = 0; i < 4; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
    }
    else if (shapeNum == 2 )
    {
        removeRow--;
        removeCol += 3;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
        removeRow++;
        removeCol--;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
    }
    else if (shapeNum == 3 )
    {
        removeCol += 2;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
        removeRow++;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
    }
    else if (shapeNum == 5 )
    {
        removeRow--;
        removeCol++;
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeRow++;
        boardArr[removeRow][removeCol] = '-';
    }
     else if (shapeNum == 6 )
    {
        removeRow++;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
        removeCol++;
        removeRow++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
    }
    else if (shapeNum == 7 )
    {
        removeCol += 3;
        removeRow--;
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
        removeRow++;
        removeCol--;
        boardArr[removeRow][removeCol] = '-';
    }
    }
    else if(Rotate==2){
         if (shapeNum == 1 )
    {
        removeRow += 2;
        for (int i = 0; i < 4; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
    }
    else if (shapeNum == 2 )
    {
        removeRow++;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeRow++;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }

    }
    else if (shapeNum == 3 )
    {
        removeRow++;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeRow++;
        removeCol--;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
    }
    else if (shapeNum == 5 )
    {
        removeCol += 2;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeRow++;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
    }
    else if (shapeNum == 6 )
    {

        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
        removeCol++;
        boardArr[removeRow][removeCol] = '-';
    }
    else if (shapeNum == 7 )
    {
        removeCol += 2;
        removeRow++;
        boardArr[removeRow][removeCol] = '-';
        removeRow++;
        removeCol--;
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
    }
    }
    else if(Rotate==3){
        if (shapeNum == 1 )
    {
        removeRow--;
        for (int i = 0; i < 4; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
    }
    else if (shapeNum == 2 )
    {

        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow][removeCol] = '-';
        }
        removeRow++;
        removeCol--;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
    }
    else if (shapeNum == 3 )
    {
        removeRow--;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
        removeRow++;
        removeCol++;
        for (int i = 0; i < 2; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }
    }
    else if (shapeNum == 5 )
    {
        removeRow++;
        removeCol += 2;
        boardArr[removeRow][removeCol] = '-';
        removeRow++;
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow][removeCol - i] = '-';
        }
    }
    else if (shapeNum == 6 )
    {
        removeRow--;
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow][removeCol + i] = '-';
        }
        removeRow++;
        removeCol += 2;
        boardArr[removeRow][removeCol] = '-';
    }
    else if (shapeNum == 7 )
    {
        for (int i = 0; i < 3; i++)
        {
            boardArr[removeRow + i][removeCol] = '-';
        }

        removeRow++;
        removeCol++;
        boardArr[removeRow][removeCol] = '-';
    }
    }
}
void removeARow(char boardArr[][30], int row)
{
    for (int i = 1; i < 29; i++)
    {
        boardArr[row][i] = '-';
    }
    for (int i = 0; i <= row; i++)
    {
        for (int j = 1; j < 29; j++)
        {
            boardArr[row][j] = boardArr[row - 1][j];
        }
        row--;
    }
}
void saveArr(char boardArr[][30], int cScore)
{
    ofstream write("save.txt");
    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            write << boardArr[i][j];
        }
        write << endl;
    }
    write << cScore ;
}
void blockMovement(int height, char boardArr[][30], char ch, char shape[][4], int srow, int scol, int shapeNum, int &Rotate, int cScore)
{
    int firstElem = 13, lastElem = 16;
    int currentRow = 0;

    while (true)
    {
        saveArr(boardArr, cScore);


        // printing shape

        for (int i = 0; i < srow; i++)
        {
            for (int j = 0; j < scol; j++)
            {
                if (shape[i][j] == ch)
                {
                    boardArr[currentRow][firstElem+j] = shape[i][j];
                }
            }
            currentRow++;
        }
        currentRow -= 3;


        gotoRowCol(0, 0);
        printBoard(height, boardArr);
        if (Collision(currentRow, shapeNum, Rotate, firstElem, lastElem, boardArr, ch))
        {
            int resetShapeIter;
            if (Rotate == 1)
            {
                resetShapeIter = 3;
            }
            else if (Rotate == 2)
            {
                resetShapeIter = 2;
            }
            else if (Rotate == 3)
            {
                resetShapeIter = 1;
            }
            for (int i = 1; i <= resetShapeIter; i++)
            {
                shapeRotation(shape, srow, scol);
            }
            Rotate = 0;
            break;
        }
        // erasing shape

        erasingShapes(shapeNum, Rotate, boardArr, currentRow, firstElem);

            if (kbhit())
        {
            int key = getch();
            if (key == 72 || key == 80)
            {
                if (shapeNum != 4)
                {
                    shapeRotation(shape, srow, scol);
                    if (Rotate == 3)
                    {
                        Rotate = 0;
                    }
                    else
                    {
                        Rotate += 1;
                    }
                }
            }
            // right

            if (key == 77)
            {
                int lastColShape=lastElem;
                int lastRowShape=currentRow;

                if((shapeNum == 7 && Rotate == 0)||(shapeNum == 6 && Rotate == 3)||(shapeNum == 5 && Rotate == 3)||(shapeNum == 4)||(shapeNum == 3 && Rotate == 0)||(shapeNum == 3 && Rotate == 2)||(shapeNum == 2 && Rotate == 0)){
                    lastColShape = lastElem - 1;
                }
                else if((shapeNum == 7 && Rotate == 3)||(shapeNum == 6 && Rotate == 2)||(shapeNum == 5 && Rotate == 0)||(shapeNum == 3 && Rotate == 3)||(shapeNum == 2 && Rotate == 3)){
                    lastColShape = lastElem - 2;
                }
                else if((shapeNum == 1 && Rotate == 3)){
                    lastColShape = lastElem - 3;
                }
                if((shapeNum == 7 && Rotate == 0)||(shapeNum == 5 && Rotate == 1)||(shapeNum == 3 && Rotate == 0)||(shapeNum == 1 && Rotate == 0)){
                    lastRowShape = currentRow-1;
                }
                else if((shapeNum == 7 && Rotate == 2)||(shapeNum == 6 && Rotate == 1)||(shapeNum == 2 && Rotate == 2)||(shapeNum == 1 && Rotate == 2)){
                    lastRowShape = currentRow +2;
                }
                else if((shapeNum == 7 && Rotate == 3)||(shapeNum == 5 && Rotate == 0)||(shapeNum == 5 && Rotate == 3)||(shapeNum == 3 && Rotate == 1)||(shapeNum == 3 && Rotate == 2)){
                    lastRowShape = currentRow +1;
                }

                if (lastColShape + 1 < 29 && boardArr[lastRowShape][lastColShape + 1] != ch)
                {
                    firstElem++;
                    lastElem++;
                }
            }

            // left
            if (key == 75)
            {
                int firstColShape =firstElem;
                int firstRowShape=currentRow;
                if((shapeNum == 1 && Rotate == 1)){
                    firstColShape = firstElem + 3;
                }
                else if((shapeNum == 2 && Rotate == 1)||(shapeNum == 3 && Rotate == 1)||(shapeNum == 5 && Rotate == 2)||(shapeNum == 6 && Rotate == 0)||(shapeNum == 7 && Rotate == 1)){
                    firstColShape = firstElem + 2;
                }
                else if((shapeNum == 2 && Rotate == 2)||(shapeNum == 3 && Rotate == 0)||(shapeNum == 4)||(shapeNum == 5 && Rotate == 1)||(shapeNum == 6 && Rotate == 1)||(shapeNum == 7 && Rotate == 2)){
                    firstColShape = firstElem + 1;
                }

                if((shapeNum == 2 && Rotate == 0)||(shapeNum == 6 && Rotate == 3)||(shapeNum == 7 && Rotate == 0)){
                    firstRowShape = currentRow-1;
                }
                else if((shapeNum == 2 && Rotate == 2)||(shapeNum == 2 && Rotate == 3)||(shapeNum == 6 && Rotate == 0)||(shapeNum == 6 && Rotate == 1)){
                    firstRowShape = currentRow+1;
                }
                else if((shapeNum == 3 && Rotate == 2)||(shapeNum == 5 && Rotate == 3)||(shapeNum == 7 && Rotate == 2)){
                    firstRowShape = currentRow+2;
                }



                if (firstColShape - 1 > 0 && boardArr[firstRowShape][firstColShape - 1] != ch)
                {
                    firstElem--;
                    lastElem--;
                }
            }
        }

    }
}
void loadArr(char boardArr[][30],int rows,int &cScore){
     ifstream read("save.txt");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < 30; j++)
                {

                    read >> boardArr[i][j];
                }
            }
            read >> cScore;
}
int main()
{
    int height = 35;
    char boardArr[height][30];
    char blockElement = 219;

    char Line[4][4] = {{blockElement, blockElement, blockElement, blockElement},
                       {'-', '-', '-', '-'},
                       {'-', '-', '-', '-'},
                       {'-', '-', '-', '-'}};
    char Zed[4][4] = {{blockElement, blockElement, '-', '-'},
                      {'-', blockElement, blockElement, '-'},
                      {'-', '-', '-', '-'},
                      {'-', '-', '-', '-'}};
    char S[4][4] = {{'-', '-', blockElement, blockElement},
                    {'-', blockElement, blockElement, '-'},
                    {'-', '-', '-', '-'},
                    {'-', '-', '-', '-'}};
    char Square[4][4] = {{'-', blockElement, blockElement, '-'},
                         {'-', blockElement, blockElement, '-'},
                         {'-', '-', '-', '-'},
                         {'-', '-', '-', '-'}};
    char L[4][4] = {{blockElement, '-', '-', '-'},
                    {blockElement, '-', '-', '-'},
                    {blockElement, blockElement, '-', '-'},
                    {'-', '-', '-', '-'}};
    char J[4][4] = {{'-', '-', '-', blockElement},
                    {'-', '-', '-', blockElement},
                    {'-', '-', blockElement, blockElement},
                    {'-', '-', '-', '-'}};
    char T[4][4] = {{blockElement, blockElement, blockElement, '-'},
                    {'-', blockElement, '-', '-'},
                    {'-', '-', '-', '-'},
                    {'-', '-', '-', '-'}};

    int shapeRows = 4, shapeCols = 4;
    int shapeRotate = 0;
    int shapeStart = 13, shapeEnd = 16;
    int currentScore = 0;
    // shapeRotation(J, shapeRows,shapeCols);
  /* for (int i = 0; i < shapeRows; i++){
        for (int j = 0; j < shapeCols; j++){
            cout<<Line[i][j]<<" ";
        }
        cout<<endl;
    }
cout<<endl;
    shapeRotation(Line,shapeRows,shapeCols);
    for (int i = 0; i < shapeRows; i++){
        for (int j = 0; j < shapeCols; j++){
            cout<<Line[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    shapeRotation(Line,shapeRows,shapeCols);
    for (int i = 0; i < shapeRows; i++){
        for (int j = 0; j < shapeCols; j++){
            cout<<Line[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    shapeRotation(Line,shapeRows,shapeCols);
    for (int i = 0; i < shapeRows; i++){
        for (int j = 0; j < shapeCols; j++){
            cout<<Line[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    shapeRotation(Line,shapeRows,shapeCols);
    for (int i = 0; i < shapeRows; i++){
        for (int j = 0; j < shapeCols; j++){
            cout<<Line[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    char choice;
    do
    {

        cout << "Press 'L' or 'l' to load game and 'N' or 'n' for new game: ";
        cin >> choice;
        if (choice == 'L' || choice == 'l')
        {
           loadArr(boardArr,height,currentScore);
        }
        else if (choice == 'N' || choice == 'n')
        {
            fillBoard(height, boardArr, blockElement);
            currentScore = 0;
            saveArr(boardArr,  currentScore);
        }
    } while (choice != 'L' && choice != 'l' && choice != 'N' && choice != 'n');
    system("CLS");
    printBoard(height, boardArr);

    gotoRowCol(1, 60);
    cout << "Score: " << currentScore;
    while (true)
    {
        srand(time(0));
        int randomShape = (rand() % 7) + 1;
        if (randomShape == 1)
        {
            blockMovement(height, boardArr, blockElement, Line, shapeRows, shapeCols, randomShape, shapeRotate, currentScore);
        }
        else if (randomShape == 2)
        {
            blockMovement(height, boardArr, blockElement, Zed, shapeRows, shapeCols, randomShape, shapeRotate, currentScore);
        }
        else if (randomShape == 3)
        {
            blockMovement(height, boardArr, blockElement, S, shapeRows, shapeCols, randomShape, shapeRotate, currentScore);
        }
        else if (randomShape == 4)
        {
            blockMovement(height, boardArr, blockElement, Square, shapeRows, shapeCols, randomShape, shapeRotate, currentScore);
        }
        else if (randomShape == 5)
        {
            blockMovement(height, boardArr, blockElement, L, shapeRows, shapeCols, randomShape, shapeRotate, currentScore);
        }
        else if (randomShape == 6)
        {
            blockMovement(height, boardArr, blockElement, J, shapeRows, shapeCols, randomShape, shapeRotate, currentScore);
        }
        else if (randomShape == 7)
        {
            blockMovement(height, boardArr, blockElement, T, shapeRows, shapeCols, randomShape, shapeRotate, currentScore);
        }
       // currentScore += 10;
        gotoRowCol(1, 60);
        cout << "Score: " << currentScore;
        for (int i = 0; i < height - 1; i++)
        {

            if (boardArr[i][0] == blockElement && boardArr[i][1] == blockElement && boardArr[i][2] == blockElement && boardArr[i][3] == blockElement && boardArr[i][4] == blockElement && boardArr[i][5] == blockElement && boardArr[i][6] == blockElement && boardArr[i][7] == blockElement && boardArr[i][8] == blockElement && boardArr[i][9] == blockElement && boardArr[i][10] == blockElement && boardArr[i][11] == blockElement && boardArr[i][12] == blockElement && boardArr[i][13] == blockElement && boardArr[i][14] == blockElement && boardArr[i][15] == blockElement && boardArr[i][16] == blockElement && boardArr[i][17] == blockElement && boardArr[i][18] == blockElement && boardArr[i][19] == blockElement)
            {
                cout<<"\a\a";
                removeARow(boardArr, i);
                currentScore += 100;

                gotoRowCol(1, 60);
                cout << "Score: " << currentScore;
                for (int i = 1; i < 29; i++)
                {
                    boardArr[0][i] = '-';
                }
            }
        }
        saveArr(boardArr,currentScore);
        if (boardArr[3][shapeStart] == blockElement || boardArr[3][shapeStart+1] == blockElement || boardArr[3][shapeStart+2] == blockElement || boardArr[3][shapeStart+3] == blockElement)
        {
            system("CLS");
            gotoRowCol(5,20);
            cout<<"Score: "<<currentScore;
            gotoRowCol(10,20);
            cout<<"GAME OVER!!!"<<endl<<endl<<endl;
            sleep(20000);
            break;
        }
    }
    return 0;
}
