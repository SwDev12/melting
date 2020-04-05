all: melting best_melt

melting: melting.c
	gcc melting.c -Wall -Wextra -Werror -std=c11 -O0 -o melting

best_melt: best_melt.c
	gcc melting.c -Wall -Wextra -Werror -std=c11 -O0 -o best_melt

clean:
	rm melting
