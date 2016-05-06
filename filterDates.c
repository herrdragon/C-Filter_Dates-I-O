// filterDates.c
/******************************************************************************/
/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #5.   DUE Tuesday 4/05
*/
/*DESCRIPTION: functions to read dates and validate them.
*/
/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/
/******************************************************************************/
#include <stdio.h>
#include <limits.h> /* for INT_MIN and INT_MAX */
#include <stdlib.h> /* for atoi() */
#include <unistd.h> /* for close() */
#include <ctype.h>  /* for isdigit() */
#include "dates.h"  /* definition for types and function prototype */
/******************************************************************************/
/* Used for days of the month */
const int daytable[MONTHS] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Used for name of the month */
const char monthName[MONTHS][MONTHS] = {"BAD MONTH", "JAN", "FEB", "MAR", "APR",
 "MAY", "JUN","JUL", "AGO", "SET", "OCT", "NOV", "DIC"};
/******************************************************************************/
//   FUNCTIONS for weriteDates.c
/******************************************************************************/
/*
* Function: printGoodDates
* ------------------------
* Reads input data in m/d/y format and print in day, abbreviated month & year 
* format.
*
* arg: int day, int month, int year.
* return: void
* side sffects: none.
*/
void printGoodDates(int month, int day, int year) {
    while(scanf("%d%d%d",&month,&day,&year) != EOF && month != 0) {
        printf("%d %s %d\n" ,day,monthName[month],year);
    }
    printf("%s\n", "");
}
/******************************************************************************/
/*
* Function: printAllDates
* -----------------------
* Reads all data from input file and print it to the output file.
*
* arg: char buf: save data for processing, char file: name of input file.
* return: void
* side sffects: none.
*/
void printAllDates(char buf[], char file[]) {
    FILE *fileToRead;
    fileToRead = fopen(file,"r");

    while (fgets(buf,1000, fileToRead) != NULL) {
        printf("%s",buf);
    }

    printf("%s\n", "");
    fclose(fileToRead);
}
/******************************************************************************/
 //  FUNCTIONS for readDates.c
/******************************************************************************/
/*
* Function: getAllData
* ---------------------
* Reads all input data.
*
* arg: int day: of the month, int month: of the year, int year, 
* char buf: save data for processing.
* return: void
* side sffects: none.
*/
void getAllData(int month, int day, long year, char buf[]) {
    while(scanf("%s",buf) != EOF) {
        if(sscanf(buf, "%d/%d/%ld",&month,&day,&year) == DATEFORMAT) {
            if(isOkDate(month, day, year)) {
                printf("%d %d %ld\n" ,month,day,year);
            }
        }
    }
}
/******************************************************************************/
/*
* Function: getSomeData
* ----------------------
* Reads the amount of data indicatede by a parameter.
*
* arg: int dToRead: the amount of data to read, int day: of the month, int 
* month: of the year, long year, char buf: save data for processing
* return: void
* side sffects: none.
*/
void getSomeData(int dToRead, int month, int day, long year, char buf[]) {
    while(scanf("%s",buf) != EOF) {
        if(dToRead > 0) {
            if(sscanf(buf, "%d/%d/%ld",&month,&day,&year) == DATEFORMAT) {
                if(isOkDate(month, day, year)) {
                    printf("%d %d %ld\n" ,month,day,year);
                    dToRead--;
                }
            }
        }
        else
            return;
    }
}
/******************************************************************************/
/*
* Function: isOkDate
* -------------------
* Verify that the dates are in valid format and range.
*
* arg: int day, int month, long year.
* return: FALSE if date is not in valid format & range.  Returns TRUE otherwise.
* side sffects: none.
*/
int isOkDate(int month, int day, long year) {
    if(!isDay(day)) //validate day
        return FALSE;

    if(!isMonth(month)) //validate month
       return FALSE;

    if(!isYear(year)) //validate year
        return FALSE;
    //validate leap year
    if(month == FEB && day == LEAPDAY && year >= FIRSTLEAP) { 
        if(!isLeap(year))
            return FALSE;
    }
    else if(!(day <= daytable[month])) //validate days of month
        return FALSE;

    return TRUE;
}
/******************************************************************************/
/*
* Function: isDay
* ----------------
* Helper function to verify that the days are within the range.
*
* arg: int day: of the month.
* return: FALSE if day is not within the range.  Returns TRUE otherwise.
* side sffects: none.
*/
int isDay(int day) {
    if(day > 0 && day < DAYS)
        return TRUE;
    return FALSE;
}
/******************************************************************************/
/*
* Function: isMonth
* ------------------
* Helper function to verify that the months are within the range.
*
* arg: int month: of the year.
* return: FALSE if month is not within the range.  Returns TRUE otherwise.
* side sffects: none.
*/
int isMonth(int month) {
    if(month > 0 && month < MONTHS)
        return TRUE;
    return FALSE;
}
/******************************************************************************/
/*
* Function: isYear
* -----------------
* Helper function to verify that the year is a valid number between the maximum 
* and minimum system integer.
*
* arg: long year.
* return: FALSE if year is not within the range.  Returns TRUE otherwise.
* side sffects: none.
*/
int isYear(long year) {
    if(year >= INT_MIN && year <= INT_MAX)
        return TRUE;
    return FALSE;
}
/******************************************************************************/
/*
* Function: isLeap
* -----------------
* Helper function to verify if the years are leap or not.
*
* arg: long year.
* return: FALSE if year is not leap.  Returns TRUE otherwise.
* side sffects: none.
*/
int isLeap(long year) {
    if(((int)year % 4 == 0 && (int)year % 100 != 0) || (int)year % 400 == 0)
        return TRUE;
    return FALSE;
}
