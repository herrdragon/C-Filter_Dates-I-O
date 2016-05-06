// readDates.c
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h> /* for atoi() */
#include <ctype.h>  /* for isdigit() */
#include <unistd.h> /* for close() */
#include "dates.h"  /* definition for types and function prototype */
/******************************************************************************/
/* DOCUMENTATION */

/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #5.   DUE Tuesday 4/05 
*/

/* DESCRIPTION: Program that converts list of dates from month/day/year format 
 (1/1/1900) and validates them to day, abbreviated month & year format 
 (1 JAN 1900). This validated input will then be piped out to a second program.
*/

/* SPECIFICATIONS: Implement a pair of programs that will interface and exchange
 data — in this case, a list of dates. 
*/

/* INPUT: Accept input via the command-line arguments. Input will be the number 
 of valid entries to be redirected from the dates input file (dates.dat). 
 A zero indicates to input all entries from the dates input file.
*/

/* COMPILATION: gcc readDates.c filterDates.c -o readDates.out */

/* EXECUTE: ./readDates.out < dates.dat 0 */

/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/

/* START PSEUDO CODE
 int main(int argc, char *argv[]) {
    if (inputsIsValid(argc == 2)){
        convert strings argv[1] to integers to int amountOfData;
        if (amountOfData == 0)
            getAllData();
        else
            getSomeData(amountOfData);
    }
    else
        printf(“%s\n”, “Some Error”);

    return 0;
}
 END PSEUDO CODE */
/******************************************************************************/
int main(int argc, char *argv[]) {
    int day = 0, month = 0, dToRead = 0;
    long year = 0;
    char buf[DATALENGTH];

    // parameters check and error handling
    if(argc == 2) {
        dToRead = atoi(argv[1]); // how many data to read
        if(dToRead < 0 || !isdigit(*argv[1])) {
            // print an error & break the pipe 
            fprintf(stderr, "You entered an invalid number of data to read.\n");
            exit(1);
        }
    }
    else {
        // print an error & break the pipe 
        fprintf(stderr, "You did not enter the number of data to read.");
        fprintf(stderr, " 0 means all data.\n");
        exit(2);
    }
    // handling data
    if(dToRead == 0) //read all data
        getAllData(month, day, year, buf); 
    else //read 'dToRead' amount of data
        getSomeData(dToRead, month, day, year, buf); 
    
    printf("%s\n", "");

return NOERRORS;
}
