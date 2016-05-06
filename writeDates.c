// writeDates.c
/******************************************************************************/
#include <stdio.h>
#include "dates.h"  /* definition for types and function prototype */
/******************************************************************************/
/* DOCUMENTATION */

/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #5.   DUE Tuesday 4/05 
*/

/* DESCRIPTION: Program that accept validated dates in the month/day/year format
 and convert each of them to the day, abbreviated month & year format. The 
 abbreviated month consist of the first three letters of the month, capitalized.
 These converted results will be redirected to the output file (output.dat), 
 followed by a copy of the original (dates.dat) data. */

/* SPECIFICATIONS: Implement a pair of programs that will interface and exchange
 data — in this case, a list of dates. */

/* INPUT: The input file (dates.dat), which is accessed by the first program. */

/* COMPILATION: gcc writeDates.c filterDates.c -o writeDates.out */

/* EXECUTE: ./writeDates.out > output.dat */

/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/

/* START PSEUDO CODE
 int main(int argc, char *argv[]) {
    printGoodDates(m, d, y);
    printAllDates(buffer[], "nameOfFile.dat");
    return 0;
}
 END PSEUDO CODE */
/******************************************************************************/
int main(int argc, char *argv[]) {
    int day = 0, month = 0, year = 0;
    char buf[1000];

    printf("%s\n", "Good dates from input:");
    printGoodDates(month, day, year);
    
    
    printf("%s\n", "All dates from input:");
    printAllDates(buf, "dates.dat");

    return NOERRORS;
}
