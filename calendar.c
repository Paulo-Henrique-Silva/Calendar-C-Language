//this was made by: Paulo
//github: Paulo-Henrique-Silva

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int days[6][7];
const char ADVANCE = 'D', RETREAT = 'A', EXITPROGRAM = 'E';

enum months 
{
    january = 1, february, march, april, may, june, july, august, september,
    october, november, december
};

void refreshCalendar(int daysAmount, int monthNum, int yearNum); 

int calculatesYear(char op, int monthNum, int yearNum);
int calculatesMonth(char op, int monthNum);
int calculatesDay(int monthNum, int yearNum); 

char *monthSymbol(int monthNum);
void assignDays(int daysAmount, int monthNum, int yearNum);
int firstDay_ofWeek_inMonth(int monthNum, int yearNum);
int numOf_month(int monthNum);
//functions prototypes

int main()
{ 
    int monthNum = 12, yearNum = 2021, daysAmount = 31; //starts at 2021/12/01 
    char operation = '\0';

    while(operation != EXITPROGRAM)
    {
        system("cls");
        refreshCalendar(daysAmount, monthNum, yearNum); 

        printf("\n\n\n\t\t\t<- A        Exit - E / Change View - Q        D ->\n\n");
        operation = getch();

        operation = toupper(operation); //lowercase to uppercase
        
        yearNum = calculatesYear(operation, monthNum, yearNum); 
        monthNum = calculatesMonth(operation, monthNum);
        daysAmount = calculatesDay(monthNum, yearNum);
    }

    
    return 0;
}


void refreshCalendar(int daysAmount, int monthNum, int yearNum)
{
    int i, j;

    assignDays(daysAmount, monthNum, yearNum); 

    printf("\n\t\t\t\t\t     %s - %d", monthSymbol(monthNum), yearNum);
    printf("\n\t\t\t\t-------------------------------------");
    printf("\n\t\t\t\t SUN  MON  TUE  WED  THU  FRI  SAT");

    for(i = 0; i < 6; i++)
    {
        printf("\n\t\t\t\t  ");
        for(j = 0; j < 7; j++)
        {
            if(days[i][j] == 0)
                printf("     ", days[i][j]);
            else if(days[i][j] > 9)
                printf("%d   ", days[i][j]);
            else
                printf("%d    ", days[i][j]);
        }
    }
    //print days
}

int calculatesYear(char op, int monthNum, int yearNum)
{
    if(op == ADVANCE && monthNum == 12) 
        yearNum++;
    //if the user ADVANCEd and the month is 12, it means it's going to pass a year

    if(op == RETREAT && monthNum == 1)
        yearNum--;

    if(yearNum == 1900)
        yearNum = 1901;
    //1900 is the MIN year
    
    if(yearNum == 2100)
        yearNum = 2099;
    //MAX year

    return yearNum;
}
//ADVANCEs or RETREATs years

int calculatesMonth(char op, int monthNum)
{
    if(op == ADVANCE)
        monthNum++;
    else if(op == RETREAT)
        monthNum--;

    if(monthNum > 12) //it means it passed a year
        monthNum = 1;
    
    if(monthNum < 1)
        monthNum = 12;

    return monthNum;
}
//ADVANCEs or RETREATs months

int calculatesDay(int monthNum, int yearNum)
{
    int i;

    if(monthNum == 2 && yearNum % 4 == 0) //leap year
        return 29;
    else if(monthNum == 2 && yearNum % 4 != 0)
         return 28;
    else
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
        //the months with 31 days are: jan, mar, may, jul, aug, oct and dec
        //the last loop will pass by the values of each month
        //if the month matches, it means it has 31 days

        //30 days month
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
} 
//calculates the amount of days in month

char *monthSymbol(int monthNum)
{
    switch(monthNum)
    {
        case january:
            return "JAN";
        case february:
            return "FEB";
        case march:
            return "MAR";
        case april:
            return "APR";
        case may:
            return "MAY";
        case june:
            return "JUN";
        case july:
            return "JUL";
        case august:
            return "AUG";
        case september:
            return "SEP";
        case october:
            return "OCT";
        case november:
            return "NOV";
        case december:
            return "DEC";
    }
}
//returns the month abbreviation

void assignDays(int daysAmount, int monthNum, int yearNum)
{
    int i, j, k = 1; 
    int firstDay_ofmonth = firstDay_ofWeek_inMonth(monthNum, yearNum);

    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 7; j++)
        {
            if((i == 0 && j < firstDay_ofmonth) || k > daysAmount) 
                days[i][j] = 0;
            else
            {
                days[i][j] = k;
                k++;
            }
        }
        //starts to assign in 1st day of 1st week
    } 
}
//assigns days based in number of days in that month 


int firstDay_ofWeek_inMonth(int monthNum, int yearNum)
{
    int numOf_year, sum;
    int lastTwo_digits = yearNum % 100; 

    if(yearNum <= 1999)
        numOf_year = 0;
    else
        numOf_year = 6;
    //this calendar goes from 1901 to 2099. 
    //Therefore there is no need to know others centuries nums.

    sum = lastTwo_digits + lastTwo_digits / 4 + 1 + numOf_month(monthNum) + numOf_year;

    if(yearNum % 4 == 0 && (monthNum == 1 || monthNum == 2))
        sum--;

    return sum % 7;
}
/*
to calculate the day of week of any day in history, it needs to follow this steps:
    E.G: January 1st 1967

    - Take the last two digits of the year: 67
    - Divide by 4 (int): 16
    - Take the date: 1
    - Take the *month num*: 0 (see the function to know the number)
    - Take the *century num*: 0 (1900 - 1999 is 0 and 2000 - 2099 is 6)

    - Sum the number: 84

     - > if it is a leap year and month is february or januay, subtract one of sum value.
    (it's not the case)

    - Calculates the sum modulus by 7: 0

    How sunday is the 0 day of week and saturday is 6th, 
    The week day of 1967/01/01 is SUNDAY 
*/

int numOf_month(int monthNum)
{
    switch(monthNum)
    {
       case january:
            return 0;
        case february:
            return 3;
        case march:
            return 3;
        case april:
            return 6;
        case may:
            return 1;
        case june:
            return 4;
        case july:
            return 6;
        case august:
            return 2;
        case september:
            return 5;
        case october:
            return 0;
        case november:
            return 3;
        case december:
            return 5;
    }
}
//these numbers do not have a clear logic. They are just numbers that you need to use in sum