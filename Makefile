CC = gcc
CFLAGS = -mavx -mfma -fopenmp 	-std=c99 -Wall -Werror -O0

default: compute_pi.o
	$(CC) $(CFLAGS) compute_pi.o clock_pi.c -o time_test

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

run:
	for i in `seq 1000 10000 101000`; do \
		./time_test $$i ;\
	done
clean:
	rm -f *.o *.s