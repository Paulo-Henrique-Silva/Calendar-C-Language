//this was made by: Paulo
//github: Paulo-Henrique-Silva

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int days[5][7] = {'\0'}; 
const char advance = 'D', retreat = 'A', exitProgram = 'E';

void refreshCalendar(int monthNum, int year); 

int calculatesMonth(char op, int monthNum);
int calculatesYear(char op, int monthNum, int yearNum);
//functions prototypes

int main()
{ 
    int monthNum = 12, yearNum = 2021; //starts at 2021/12/01 
    char operation = '\0';

    while(operation != exitProgram)
    {
        system("cls");
        refreshCalendar(monthNum, yearNum); 

        printf("\n\n\n\t\t\t<- 'A'        Exit: 'E'        'D'->\n\n");
        operation = getch();

        operation = toupper(operation); //lowercase to uppercase
        monthNum = calculatesMonth(operation, monthNum);
        yearNum = calculatesYear(operation, monthNum, yearNum); 
    }

    return 0;
}

void refreshCalendar(int monthNum, int yearNum)
{
    char monthLetters[4];

    switch(monthNum)
    {
        case 1:
            strcpy(monthLetters, "JAN");
            break;
        case 2:
            strcpy(monthLetters, "FEB");
            break;
        case 3:
            strcpy(monthLetters, "MAR");
            break;
        case 4:
            strcpy(monthLetters, "APR");
            break;
        case 5:
            strcpy(monthLetters, "MAY");
            break;
        case 6:
            strcpy(monthLetters, "JUN");
            break;
        case 7:
            strcpy(monthLetters, "JUL");
            break;
        case 8:
            strcpy(monthLetters, "AUG");
            break;
        case 9:
            strcpy(monthLetters, "SEP");
            break;
        case 10:
            strcpy(monthLetters, "OCT");
            break;
        case 11:
            strcpy(monthLetters, "NOV");
            break;
        case 12:
            strcpy(monthLetters, "DEC");
            break;
    }

    printf("\n\t\t\t\t      %s - %d", monthLetters, yearNum);
    printf("\n\t\t\t\t--------------------");
    printf("\n\t\t\t\t S  M  T  W  T  F  S");
    printf("\n\t\t\t\t       1  2  3  4  5");
    printf("\n\t\t\t\t 6  7  8  9 10 11 12");
    printf("\n\t\t\t\t13 14 15 16 17 18 19");
    printf("\n\t\t\t\t20 21 22 23 24 25 26");
    printf("\n\t\t\t\t27 28 29 30 31      ");
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

int calculatesYear(char op, int monthNum, int yearNum)
{
    if(op == advance && monthNum == 1) 
        yearNum++;
    //if the user advanced and the result month is 1, it means it passed the year

    if(op == retreat && monthNum == 12)
        yearNum--;

    return yearNum;
}