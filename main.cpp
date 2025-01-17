#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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
            if (i == 29 || j==0||j==19)
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
            cout << arr[i][j]<<" ";
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
    //reverse rows
    for(int i=0;i<row;i++){
        int start = 0, endd=col-1;
    while(start<endd){
        int temp = shape[i][start];
        shape[i][start] = shape[i][endd];
        shape[i][endd] = temp;
        start++;
        endd--;
    }
    }

}
void shapeRotation270(char shape[][4], int row, int col)
{
    //transpose
    //reverse columns
}
bool Collision(int breakRow, int shapeNum, int Rotate, int &firstElem,int &lastElem, char boardArr[][20], char ch){

        if (shapeNum == 1 && Rotate == 1)
        {
            breakRow += 3;
        }
        else if (shapeNum == 1 && Rotate == 2)
        {
            breakRow += 3;
        }
        else if (shapeNum == 1 && Rotate == 3)
        {
            breakRow += 3;
        }
        else if (shapeNum == 2 && Rotate == 0)
        {
            breakRow += 1;
        }
        else if (shapeNum == 2 && Rotate == 1)
        {
            breakRow += 2;
        }
        else if (shapeNum == 2 && Rotate == 2)
        {
            breakRow += 3;
        }
        else if (shapeNum == 2 && Rotate == 3)
        {
            breakRow += 3;
        }
        else if (shapeNum == 3 && Rotate == 0)
        {
            breakRow += 1;
        }
        else if (shapeNum == 3 && Rotate == 1)
        {
            breakRow += 3;
        }
        else if (shapeNum == 3 && Rotate == 2)
        {
            breakRow += 3;
        }
        else if (shapeNum == 3 && Rotate == 3)
        {
            breakRow += 2;
        }
        else if (shapeNum == 4)
        {
            breakRow += 1;
        }
        else if (shapeNum == 5 && Rotate == 0)
        {
            breakRow += 2;
        }
        else if (shapeNum == 5 && Rotate == 1)
        {
            breakRow += 1;
        }
        else if (shapeNum == 5 && Rotate == 2)
        {
            breakRow += 3;
        }
        else if (shapeNum == 5 && Rotate == 3)
        {
            breakRow += 3;
        }
        else if (shapeNum == 6 && Rotate == 0)
        {
            breakRow += 2;
        }
        else if (shapeNum == 6 && Rotate == 1)
        {
            breakRow += 3;
        }
        else if (shapeNum == 6 && Rotate == 2)
        {
            breakRow += 3;
        }
        else if (shapeNum == 6 && Rotate == 3)
        {
            breakRow += 1;
        }
        else if (shapeNum == 7 && Rotate == 0)
        {
            breakRow += 1;
        }
        else if (shapeNum == 7 && Rotate == 1)
        {
            breakRow += 2;
        }
        else if (shapeNum == 7 && Rotate == 2)
        {
            breakRow += 3;
        }
        else if (shapeNum == 7 && Rotate == 3)
        {
            breakRow += 3;
        }
        gotoRowCol(5, 60);
        cout << breakRow;


        //sleep(6000);
        if(shapeNum==1 && Rotate==0){
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }}
        else if(shapeNum==1 && Rotate==1){
            if (boardArr[breakRow][firstElem+3] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }
        }
        else if(shapeNum==1 && Rotate==2){
        if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch || boardArr[breakRow][firstElem + 3] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }}
        if(shapeNum==1 && Rotate==3){
        if (boardArr[breakRow][firstElem] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }}

        else if(shapeNum==2 && Rotate==0){
            if (boardArr[breakRow-1][firstElem] == ch||boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }}
        else if(shapeNum==2 && Rotate==1){
            if (boardArr[breakRow][firstElem+2] == ch || boardArr[breakRow-1][firstElem+3] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==2 && Rotate==2){
            if (boardArr[breakRow-1][firstElem+1] == ch || boardArr[breakRow][firstElem+2] == ch|| boardArr[breakRow][firstElem+3] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==2 && Rotate==3){
            if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow-1][firstElem+1] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }

        else if(shapeNum==3 && Rotate==0){
            if (boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch ||  boardArr[breakRow-1][firstElem + 3] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }
        }
        else if(shapeNum==3 && Rotate==1){
            if (boardArr[breakRow-1][firstElem+2] == ch || boardArr[breakRow][firstElem+3] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==3 && Rotate==2){
            if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem+1] == ch||boardArr[breakRow-1][firstElem+2] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==3 && Rotate==3){
            if (boardArr[breakRow-1][firstElem] == ch || boardArr[breakRow][firstElem+1] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==4){
            if (boardArr[breakRow][firstElem + 1] == ch || boardArr[breakRow][firstElem + 2] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }
        }
        else if(shapeNum==5 && Rotate==0){
            if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem + 1] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }
        }
        else if(shapeNum==5 && Rotate==1){
            if (boardArr[breakRow][firstElem+1] == ch ||boardArr[breakRow-1][firstElem+2] == ch||boardArr[breakRow-1][firstElem+3] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==5 && Rotate==2){
            if (boardArr[breakRow-2][firstElem+2] == ch||boardArr[breakRow][firstElem+3] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==5 && Rotate==3){
            if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow][firstElem+1] == ch  || boardArr[breakRow][firstElem+2] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==6 && Rotate==0){
            if (boardArr[breakRow][firstElem +2] == ch || boardArr[breakRow][firstElem + 3] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }
        }
        else if(shapeNum==6 && Rotate==1){
            if (boardArr[breakRow][firstElem+1] == ch || boardArr[breakRow][firstElem+2] == ch || boardArr[breakRow][firstElem+3] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }}
        else if(shapeNum==6 && Rotate==2){
            if (boardArr[breakRow][firstElem] == ch ||boardArr[breakRow-2][firstElem+1] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }}
        else if(shapeNum==6 && Rotate==3){
            if (boardArr[breakRow-1][firstElem] == ch||boardArr[breakRow-1][firstElem+1] == ch||boardArr[breakRow][firstElem+2] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }}
        else if(shapeNum==7 && Rotate==0){
            if (boardArr[breakRow-1][firstElem] == ch|| boardArr[breakRow][firstElem + 1] == ch ||boardArr[breakRow-1][firstElem + 2] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }else{
        return 0;
        }
        }
        else if(shapeNum==7 && Rotate==1){
            if (boardArr[breakRow-1][firstElem+2] == ch||boardArr[breakRow][firstElem+3] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==7 && Rotate==2){
            if (boardArr[breakRow][firstElem+1] == ch||boardArr[breakRow][firstElem+2] == ch||boardArr[breakRow][firstElem+3] == ch )
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else if(shapeNum==7 && Rotate==3){
            if (boardArr[breakRow][firstElem] == ch || boardArr[breakRow-1][firstElem+1] == ch)
        {
           // firstElem =8;
           // lastElem =11;
            return 1;
        }
        else{
            return 0;
        }
        }
        else{
        return 0;
        }
}
void erasingShapes(int shapeNum, int Rotate, char boardArr[][20],int removeRow, int removeCol){
    if(shapeNum==1 && Rotate==0){
            for(int i=0;i<4;i++){
                boardArr[removeRow-1][removeCol+i] = '-';
            }
    }
    else if(shapeNum==1 && Rotate==1){
            removeRow--;
            removeCol+=3;
        for(int i=0;i<4;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
    }
    else if(shapeNum==1 && Rotate==2){
            removeRow+=2;
        for(int i=0;i<4;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    }
    else if(shapeNum==1 && Rotate==3){
            removeRow--;
        for(int i=0;i<4;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
    }
    else if(shapeNum==2 && Rotate==0){
            removeRow--;
        for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
            removeRow++;
            removeCol++;
        for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    }
    else if(shapeNum==2 && Rotate==1){
            removeRow--;
            removeCol+=3;
        for(int i=0;i<2;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
            removeRow++;
            removeCol--;
            for(int i=0;i<2;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
    }
    else if(shapeNum==2 && Rotate==2){
        gotoRowCol(6,60);
            cout<<removeRow;
            removeRow++;
            removeCol++;
        for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    gotoRowCol(6,60);
            cout<<removeRow;
            removeRow++;
            removeCol++;
            gotoRowCol(6,60);
            cout<<removeRow;
            for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    }
    else if(shapeNum==2 && Rotate==3){

            removeCol++;
        for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol] = '-';
            }
            removeRow++;
            removeCol--;
            for(int i=0;i<2;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
    }
    else if(shapeNum==3 && Rotate==0){
            removeCol+=2;
            removeRow--;
            for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
            removeCol-=1;
            removeRow++;
            for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    }
    else if(shapeNum==3 && Rotate==1){
            removeCol+=2;
        for(int i=0;i<2;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
            removeRow++;
            removeCol++;
            for(int i=0;i<2;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
    }
    else if(shapeNum==3 && Rotate==2){
            removeRow++;
            removeCol++;
        for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
            removeRow++;
            removeCol--;
            for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    }
    else if(shapeNum==3 && Rotate==3){
            removeRow--;
        for(int i=0;i<2;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
            removeRow++;
            removeCol++;
            for(int i=0;i<2;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
    }
    else if(shapeNum==4){
            removeRow--;
            removeCol++;
        for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
            removeRow++;
            for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    }
    else if(shapeNum==5 && Rotate==0){
            removeRow--;
        for(int i=0;i<3;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
            removeRow+=2;
            removeCol++;
            boardArr[removeRow][removeCol] = '-';
    }
    else if(shapeNum==5 && Rotate==1){
            removeRow--;
            removeCol++;
            for(int i=0;i<3;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
            removeRow++;
            boardArr[removeRow][removeCol] = '-';
    }
    else if(shapeNum==5 && Rotate==2){
            removeCol+=2;
            for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
            removeRow++;
            removeCol++;
            for(int i=0;i<2;i++){
                boardArr[removeRow+i][removeCol] = '-';
            }
    }
    else if(shapeNum==5 && Rotate==3){
            removeRow++;
            removeCol+=2;
            boardArr[removeRow][removeCol] = '-';
            removeRow++;
            for(int i=0;i<3;i++){
            boardArr[removeRow][removeCol-i] = '-';
            }

    }
    else if(shapeNum==6 && Rotate==0){
            removeCol+=3;
            removeRow--;
            for(int i=0;i<3;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
            removeCol-=1;
            removeRow+=2;
            boardArr[removeRow][removeCol] = '-';
    }
    else if(shapeNum==6 && Rotate==1){
            removeRow++;
            removeCol++;
            for(int i=0;i<2;i++){
                boardArr[removeRow+i][removeCol] = '-';
            }
            removeCol++;
            removeRow++;
            for(int i=0;i<2;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    }
    else if(shapeNum==6 && Rotate==2){

            for(int i=0;i<3;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
            removeCol++;
            boardArr[removeRow][removeCol] = '-';
    }
    else if(shapeNum==6 && Rotate==3){
            removeRow--;
            for(int i=0;i<3;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
            removeRow++;
            removeCol+=2;
            boardArr[removeRow][removeCol] = '-';

    }
    else if(shapeNum==7 && Rotate==0){
            removeRow--;
            for(int i=0;i<3;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
            removeCol+=1;
            removeRow++;
            boardArr[removeRow][removeCol] = '-';
    }
    else if(shapeNum==7 && Rotate==1){
            removeCol+=3;
            removeRow--;
            for(int i=0;i<3;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }
            removeRow++;
            removeCol--;
            boardArr[removeRow][removeCol] = '-';
    }
    else if(shapeNum==7 && Rotate==2){
            removeCol+=2;
            removeRow++;
            boardArr[removeRow][removeCol] = '-';
            removeRow++;
            removeCol--;
            for(int i=0;i<3;i++){
            boardArr[removeRow][removeCol+i] = '-';
            }
    }
    else if(shapeNum==7 && Rotate==3){
            for(int i=0;i<3;i++){
            boardArr[removeRow+i][removeCol] = '-';
            }

            removeRow++;
            removeCol++;
            boardArr[removeRow][removeCol] = '-';
    }
}
void removeARow(char boardArr[][20], int row){
    for(int i=1;i<19;i++){
        boardArr[row][i]= '-';
    }
    for(int i=0;i<=row;i++){
        for(int j=1;j<19;j++){
            boardArr[row][j] = boardArr[row-1][j];
        }
        row--;
    }
}
void blockMovement(int height, char boardArr[][20], char ch, char shape[][4] , int srow, int scol, int shapeNum, int &Rotate)
{
    int firstElem=8,lastElem=11;
    int currentRow = 0;

    while (true)
    {

        //sleep(5000);
        // int movement = getch();
        // if (movement == 80)
        //{
       // sleep(10000);
        if (kbhit())
        {
            int key = getch();
            if (key == 72 || key == 80)
            {
                if (shapeNum != 4)
                {
                    shapeRotation(shape, srow, scol);
                    if(Rotate==3){
                        Rotate=0;
                    }
                    else{
                        Rotate+=1;
                    }

                }
            }
            //right
            gotoRowCol(7, 60);
            cout << firstElem;
            gotoRowCol(9, 60);
            cout << lastElem;
            if (key == 77)
            {   int lastColShape;
                if(shapeNum==7 && Rotate==0){
                    lastColShape = lastElem-1;
                }
                else if(shapeNum==7 && Rotate==3){
                    lastColShape = lastElem-2;
                }
                else if(shapeNum==6 && Rotate==2){
                    lastColShape = lastElem-2;
                }
                else if(shapeNum==6 && Rotate==3){
                    lastColShape = lastElem-1;
                }
                else if(shapeNum==5 && Rotate==0){
                    lastColShape = lastElem-2;
                }
                else if(shapeNum==5 && Rotate==3){
                    lastColShape = lastElem-1;
                }
                else if(shapeNum==4){
                    lastColShape = lastElem-1;
                }
                else if(shapeNum==3 && Rotate==2){
                    lastColShape = lastElem-1;
                }
                else if(shapeNum==3 && Rotate==3){
                    lastColShape = lastElem-2;
                }
                else if(shapeNum==2 && Rotate==0){
                    lastColShape = lastElem-1;
                }
                else if(shapeNum==2 && Rotate==3){
                    lastColShape = lastElem-2;
                }
                else if(shapeNum==1 && Rotate==2){
                    lastColShape = lastElem-3;
                }
                else{
                    lastColShape = lastElem;
                }
                if(lastColShape+1<19){
                for (int i = 0; i < srow; i++)
                {
                    for (int j = 0; j < scol; j++)
                    {
                        int a = 1;
                        boardArr[currentRow][lastColShape+a] = boardArr[currentRow][lastColShape];
                       // lastElem--;
                       a++;
                    }
                   // lastElem-=4;
                    currentRow++;
                }
                firstElem++;
                lastElem++;
                currentRow -= 4;
                }
            }
            gotoRowCol(7, 60);
            cout << firstElem;
            gotoRowCol(9, 60);
            cout << lastElem;
            //left
            if (key == 75)
            {
                int firstColShape;
                if(shapeNum==1&&Rotate==1){
                    firstColShape = firstElem+3;
                }
                else if(shapeNum==2&&Rotate==1){
                    firstColShape = firstElem+2;
                }
                else if(shapeNum==2&&Rotate==2){
                    firstColShape = firstElem+1;
                }
                else if(shapeNum==3&&Rotate==0){
                    firstColShape = firstElem+1;
                }
                else if(shapeNum==3&&Rotate==1){
                    firstColShape = firstElem+2;
                }
                else if(shapeNum==4){
                    firstColShape = firstElem+1;
                }
                else if(shapeNum==5&&Rotate==1){
                    firstColShape = firstElem+1;
                }
                else if(shapeNum==5&&Rotate==2){
                    firstColShape = firstElem+2;
                }
                else if(shapeNum==6&&Rotate==0){
                    firstColShape = firstElem+2;
                }
                else if(shapeNum==6&&Rotate==1){
                    firstColShape = firstElem+1;
                }
                else if(shapeNum==7&&Rotate==1){
                    firstColShape = firstElem+2;
                }
                else if(shapeNum==7&&Rotate==2){
                    firstColShape = firstElem+1;
                }
                else{
                    firstColShape = firstElem;
                }

                if(firstColShape-1>0){
                for (int i = 0; i < srow; i++)
                {
                    for (int j = 0; j < scol; j++)
                    {
                        int a=1;
                        boardArr[currentRow][firstColShape-a] = boardArr[currentRow][firstColShape];
                       // firstElem--;
                       a++;
                    }
                   // firstElem+=4;
                    currentRow++;
                }
                firstElem--;
                lastElem--;
                currentRow -= 4;}
            }
            gotoRowCol(7, 60);
            cout << firstElem;
            gotoRowCol(9, 60);
            cout << lastElem;
        }

//printing shape
        /*for (int i = 0; i < srow; i++)
        {
            for (int j = 0; j < scol; j++)
            {
                if (boardArr[currentRow][firstElem] != ch || shape[i][j] != '-')
                {
                    boardArr[currentRow][firstElem] = shape[i][j];
                }
                firstElem++;
            }
            firstElem -= 4;
            currentRow++;
        }
        currentRow -= 3;*/
       for (int i = 0; i < srow; i++)
        {
            for (int j = 0; j < scol; j++)
            {
                if ( shape[i][j] == ch)
                {
                    boardArr[currentRow][firstElem] = shape[i][j];
                }
                firstElem++;
            }
            firstElem -= 4;
            currentRow++;
        }
        currentRow -= 3;

//sleep(12000);
        gotoRowCol(0, 0);
        printBoard(height, boardArr);
        if( Collision(currentRow,shapeNum,Rotate,firstElem, lastElem,boardArr,ch)){
                int resetShapeIter;
                if(Rotate==1){
                    resetShapeIter = 3;
                }
                else if(Rotate==2){
                    resetShapeIter = 2;
                }
                else if(Rotate==3){
                    resetShapeIter = 1;
                }
                for(int i=1;i<=resetShapeIter;i++){
                    shapeRotation(shape,srow,scol);
                }
                Rotate=0;
        break;
       }
//erasing shape
erasingShapes(shapeNum,Rotate,boardArr,currentRow,firstElem);
       /*for (int i = 0; i < srow; i++)
        {
            for (int j = 0; j < scol; j++)
            {
                //if(boardArr[currentRow - 1][firstElem] != '-'){
                boardArr[currentRow - 1][firstElem] = '-';
                if (shapeNum == 1)
                {
                    boardArr[currentRow][firstElem] = '-';
                    if (Rotate == 1)
                    {
                        boardArr[currentRow + 1][firstElem] = '-';
                        boardArr[currentRow + 2][firstElem] = '-';
                    }
                }
                if (shapeNum == 2)
                {
                    boardArr[currentRow][firstElem] = '-';
                    if (Rotate == 1)
                    {
                        boardArr[currentRow + 1][firstElem] = '-';
                    }
                }
                if (shapeNum == 3)
                {
                    boardArr[currentRow][firstElem] = '-';
                    boardArr[currentRow + 1][firstElem] = '-';
                    if (Rotate == 1)
                    {
                        boardArr[currentRow+2][firstElem] = '-';
                    }
                }
                if (shapeNum == 5 || shapeNum == 6)
                {
                    boardArr[currentRow][firstElem] = '-';
                    boardArr[currentRow + 1][firstElem] = '-';
                    if (Rotate == 1)
                    {
                        boardArr[currentRow + 2][firstElem] = '-';
                    }
                }
                if (shapeNum == 7)
                {
                    boardArr[currentRow][firstElem] = '-';
                    if(Rotate==1){
                        boardArr[currentRow + 1][firstElem] = '-';
                    }
                }
                if(shapeNum==4){
                    boardArr[currentRow][firstElem] = '-';
                }
               // }
                firstElem++;
            }
            firstElem -=4;
        }

*/

        gotoRowCol(0, 0);
        printBoard(height, boardArr);
        //  getch();
        //  gotoRowCol(0,0);
        //  printBoard(height, boardArr);
        /* if (kbhit())
         {
             int key = getch();
             if (key == 72 || key == 80)
             {
                 if(shapeNum!=4){
                 shapeRotation(shape, srow, scol);
                 if (Rotate == 0)
                 {
                     Rotate = 1;
                 }
                 else if(Rotate==1)
                 {
                     Rotate = 0;
                 }
                 }
             }
         }

         /* int nextLine;
          if(Rotate=0){
               nextLine = currentRow+4;
          }else if(Rotate=1){
               nextLine = currentRow;
          }*/

//sleep(8000);
        //getch();

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
    int shapeNum = 5;
    int shapeRotate = 0;
    int shapeStart = 8, shapeEnd = 11;
   // shapeRotation(J, shapeRows,shapeCols);
     /*for (int i = 0; i < shapeRows; i++){
         for (int j = 0; j < shapeCols; j++){
             cout<<J[i][j]<<" ";
         }
         cout<<endl;
     }
cout<<endl;
     shapeRotation(J,shapeRows,shapeCols);
     for (int i = 0; i < shapeRows; i++){
         for (int j = 0; j < shapeCols; j++){
             cout<<J[i][j]<<" ";
         }
         cout<<endl;
     }
     cout<<endl;
     shapeRotation(J,shapeRows,shapeCols);
     for (int i = 0; i < shapeRows; i++){
         for (int j = 0; j < shapeCols; j++){
             cout<<J[i][j]<<" ";
         }
         cout<<endl;
     }
     cout<<endl;
     shapeRotation(J,shapeRows,shapeCols);
     for (int i = 0; i < shapeRows; i++){
         for (int j = 0; j < shapeCols; j++){
             cout<<J[i][j]<<" ";
         }
         cout<<endl;
     }
     cout<<endl;
     shapeRotation(J,shapeRows,shapeCols);
     for (int i = 0; i < shapeRows; i++){
         for (int j = 0; j < shapeCols; j++){
             cout<<J[i][j]<<" ";
         }
         cout<<endl;
     }
*/
  fillBoard(height, boardArr, blockElement);
    printBoard(height, boardArr);
    while(true){
            srand(time(0));
            int randomShape = (rand()%7)+1;
    if(randomShape==1){

   blockMovement(height, boardArr, blockElement,Line , shapeRows, shapeCols, randomShape, shapeRotate);
    }
    else if(randomShape==2){

   blockMovement(height, boardArr, blockElement,Zed , shapeRows, shapeCols, randomShape, shapeRotate);
    }
    else if(randomShape==3){

   blockMovement(height, boardArr, blockElement,S , shapeRows, shapeCols, randomShape, shapeRotate);
    }
    else if(randomShape==4){

   blockMovement(height, boardArr, blockElement,Square , shapeRows, shapeCols, randomShape, shapeRotate);
    }
    else if(randomShape==5){

   blockMovement(height, boardArr, blockElement,L , shapeRows, shapeCols, randomShape, shapeRotate);
    }
    else if(randomShape==6){

   blockMovement(height, boardArr, blockElement,J , shapeRows, shapeCols, randomShape, shapeRotate);
    }
    else if(randomShape==7){

   blockMovement(height, boardArr, blockElement,T , shapeRows, shapeCols, randomShape, shapeRotate);
    }
  // shapeRotate=0;
    for(int i=0;i<height-1;i++){

        if(boardArr[i][0] == blockElement && boardArr[i][1] == blockElement && boardArr[i][2] == blockElement && boardArr[i][3] == blockElement && boardArr[i][4] == blockElement && boardArr[i][5] == blockElement && boardArr[i][6] == blockElement && boardArr[i][7] == blockElement && boardArr[i][8] == blockElement && boardArr[i][9] == blockElement && boardArr[i][10] == blockElement && boardArr[i][11] == blockElement && boardArr[i][12] == blockElement && boardArr[i][13] == blockElement && boardArr[i][14] == blockElement && boardArr[i][15] == blockElement && boardArr[i][16] == blockElement && boardArr[i][17] == blockElement && boardArr[i][18] == blockElement && boardArr[i][19] == blockElement){
            removeARow(boardArr,i);
            for(int i=1;i<19;i++){
            boardArr[0][i] = '-';
        }
        }



    }
            //shapeStart = 8;
           // shapeEnd = 11;
           // shapeRotate = 0;
    }
    return 0;
}
