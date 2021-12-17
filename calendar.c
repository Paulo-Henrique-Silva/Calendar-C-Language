//this was made by: Paulo
//github: Paulo-Henrique-Silva

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int days[5][7] = {10};
const char advance = 'D', retreat = 'A', exitProgram = 'E';

void refreshCalendar(int yearNum, int monthNum, int daysNum); 

int calculatesYear(char op, int monthNum, int yearNum);
int calculatesMonth(char op, int monthNum);
int calculatesDay(int monthNum, int yearNum); 

char *monthSymbol(int monthNum);
//functions prototypes

int main()
{ 
    int monthNum = 12, yearNum = 2021, daysNum = 31; //starts at 2021/12/01 
    char operation = '\0';

    while(operation != exitProgram)
    {
        system("cls");
        refreshCalendar(yearNum, monthNum, daysNum); 

        printf("\n\n\n\t\t\t<- 'A'        Exit: 'E'        'D' ->\n\n");
        operation = getch();

        operation = toupper(operation); //lowercase to uppercase
        
        yearNum = calculatesYear(operation, monthNum, yearNum); 
        monthNum = calculatesMonth(operation, monthNum);
        daysNum = calculatesDay(monthNum, yearNum);
    }

    
    return 0;
}


void refreshCalendar(int yearNum, int monthNum, int daysNum)
{
    int i, j, k = 1; 

    
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 7; j++)
        {
            if(k <= daysNum)
            {
                days[i][j] = k;
                k++;
            }
            else
                days[i][j] = '\0';
        }
    }

    printf("\n\t\t\t\t      %s - %d", monthSymbol(monthNum), yearNum);
    printf("\n\t\t\t\t--------------------");
    printf("\n\t\t\t\t S  M  T  W  T  F  S");

    for(i = 0; i < 5; i++)
    {
        printf("\n\t\t\t\t ");
        for(j = 0; j < 7; j++)
        {
            if(days[i][j] > 9)
                printf("%d ", days[i][j]);
            else
                printf("%d  ", days[i][j]);
        }
    }
}

int calculatesYear(char op, int monthNum, int yearNum)
{
    if(op == advance && monthNum == 12) 
        yearNum++;
    //if the user advanced and the month is 12, it means it's going to pass a year

    if(op == retreat && monthNum == 1)
        yearNum--;

    if(yearNum == 1900)
        yearNum = 1901;
    
    if(yearNum == 2100)
        yearNum = 2099;

    return yearNum;
}

int calculatesMonth(char op, int monthNum)
{
    if(op == advance)
        monthNum++;
    else if(op == retreat)
        monthNum--;

    if(monthNum > 12) //it means it passed a year
        monthNum = 1;
    
    if(monthNum < 1)
        monthNum = 12;

    return monthNum;
}

char *monthSymbol(int monthNum)
{
    switch(monthNum)
    {
        case 1:
            return "JAN";
        case 2:
            return "FEB";
        case 3:
            return "MAR";
        case 4:
            return "APR";
        case 5:
            return "MAY";
        case 6:
            return "JUN";
        case 7:
            return "JUL";
        case 8:
            return "AUG";
        case 9:
            return "SEP";
        case 10:
            return "OCT";
        case 11:
            return "NOV";
        case 12:
            return "DEC";
    }
}


int calculatesDay(int monthNum, int yearNum)
{
    int i;

    if(monthNum != 2)
    {
        //31 days month
        i = 1;
        while(i <= 12)
        {
            if(monthNum == i)
                return 31; 

            if(i == 7)
                i++;
            else
                i+=2;
        }

        i = 4;
        while(i <= 12)
        {
            if(monthNum == i)
                return 30; 

            if(i == 6)
                i+=3;
            else
                i+=2;
        }
    }
    else
    {
        if(yearNum % 4 == 0) //leap year
            return 29;
        else
            return 28; //normal feb
    }
} 