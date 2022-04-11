AUTHOR=pather
CC      = gcc
CFLAGS  = -Wall -Wextra
CFLAGS += -g -fopenmp
GNU=gnuplot
CHMOD=chmod +x
SCRIPT=script.sh
THREADPLT=plot.plt

all: main

main:
	$(CC) $(CFLAGS) matul.c -o matul

script:
	$(CHMOD) $(SCRIPT)
	./$(SCRIPT)
	$(GNU) $(THREADPLT)

gnuplot:
	$(GNU) $(THREADPLT)

clean:
	rm -f core *.o
	rm -f matmul

.PHONY: all clean main script gnuplot
