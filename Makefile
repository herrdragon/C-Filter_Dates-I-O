FILES1 = readDates.c filterDates.c
FILES2 = writeDates.c filterDates.c
CC = gcc

BUILD: $(FILES1)
	$(CC) $(FILES1) -o readDates.out
	$(CC) $(FILES2) -o writeDates.out
