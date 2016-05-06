# C-Filter_Dates-I-O
The input program converts list of dates from month/day/year format (1/1/1900) and validates them. This validated input will then be piped out to a second program.
The second program that accept validated dates in the month/day/year format and convert each of them to the day, abbreviated month & year format (1 JAN 1900). The abbreviated month consist of the first three letters of the month, capitalized. These converted results will be redirected to the output file (output.dat), followed by a copy of the original (dates.dat) data.

To use this program
--------------------
1- On the terminal, navigate to where the files are.

2- Make sure you have all six files (readDates.c, writeDates.c, filterDates.c, dates.h, dates.dat and Makefile) in the same directory.

3- Type “make” and press enter to compile the program.

4- Then type "./readDates.out < dates.dat ” follow by the number of data you would like to read, 0 means all data. Follow by pipe “|” and the second program “./writeDates.out > output.dat” like so: "./readDates.out < dates.dat 0 | ./writeDates.out > output.dat”.

5- Confirm the you have now a new file called “output.dat” containing the data from the programs.

6- If the number entered exceed the amount of data, the program will read the maximum amount of valid data.
