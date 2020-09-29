#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int id,sal;
    char name[30],addr[30];
    int dd1,mm1,yy1;                            //Date of birth.
    int dd2,mm2,yy2;                            //Date of joining.
    int day,month,year;                         //Current date.
    printf("\n*********************************************  Enter Employee Information ***************************************\n\n");
    printf("\nEnter employee id number: \n");
    scanf("%d",&id);
    gets(name);
    printf("\nEnter name of employee: \n");
    gets(name);
    printf("\nEnter address of employee: \n");
    gets(addr);
    printf("\nEnter salary of employee: \n");
    scanf("%d",&sal);

    x : printf("\nEnter date of birth (in ""DD/MM/YY"" format) of employee: \n");
    scanf("%d/%d/%d",&dd1,&mm1,&yy1);
    if(dd1>31 || mm1>12 || yy1<1800)
    {
        printf("\nInvalid date or date format!\n");
        goto x;
    }

    y : printf("\nEnter date of joining (in ""DD/MM/YY"" format) of employee: \n");
    scanf("%d/%d/%d",&dd2,&mm2,&yy2);
    if(dd2>31 || mm2>12 || yy2<1800)
    {
        printf("\nInvalid date or date format!\n");
        goto y;
    }

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    day=local->tm_mday;
    month=local->tm_mon + 1;
    year=local->tm_year + 1900;

    printf("\n***********************************************************\n");

    printf("\nAge of the employee when joined the company is %d.\n",(yy2-yy1));
    printf("\nExperience of the employee (in months) is: %d.\n",((year-yy2)*12)+(mm2-month));
    int mm3;
    mm3=mm2+3;
    if(mm3>12)
    {
        mm3=mm3-12;
        yy2++;
    }
    printf("\nProbation period of the employee is over on %d/%d/%d.\n",dd2,mm3,yy2);
    printf("\n***********************************************************\n");
    return 0;
}
