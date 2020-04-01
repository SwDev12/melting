all: melting

melting: melting.c
	gcc melting.c -Wall -Wextra -Werror -std=c11 -O0 -o melting

clean:
	rm melting
