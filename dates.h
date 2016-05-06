// dates.h
/******************************************************************************/
/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #5.   DUE Tuesday 4/05
*/
/*DESCRIPTION: header file contains common constants, declarations, prototypes 
* & type declarations that are used by readDates.c, writeDates.c, filterDates.c
*/
/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/
/******************************************************************************/
#define FIRSTLEAP   1752 //used to control leap years
#define DATALENGTH  1000 //used to control length of data
#define LEAPDAY       29 //used to check for leap year
#define MONTHS        13 //used to control day of the month
#define DAYS          32 //used to control day of the month
#define DATEFORMAT     3 //used to control date input format
#define FEB            2 //used to check for February
#define TRUE           1 //used to return 1
#define FALSE          0 //used to return 0
#define NOERRORS       0 //no errors found

const int daytable[MONTHS];   //used for day/month control
const char monthName[MONTHS][MONTHS]; //used for name of months

/******************************************************************************/
//   FUNCTIONS for weriteDates.c
/******************************************************************************/

void printGoodDates(int, int, int);

void printAllDates(char[], char[]);

/******************************************************************************/
 //  FUNCTIONS for readDates.c
/******************************************************************************/

void getAllData(int, int, long, char[]);

void getSomeData(int, int, int, long, char[]);

int isOkDate(int, int, long);

int isDay(int);

int isMonth(int);

int isYear(long);

int isLeap(long);
