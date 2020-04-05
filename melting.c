#include <stdio.h>

#define VERTICES 1008
#define INFINITE 0xfffffff

#define MAX(a, b) ((a) < (b)) ? (b) : (a)
#define MIN(a, b) ((a) > (b)) ? (b) : (a)

unsigned vert[VERTICES][VERTICES];
unsigned edges;
unsigned answer;
unsigned max_edge;

void solve(void)
{
    unsigned acc;

    for (unsigned k = 1; k <= max_edge; k++) {
        for (unsigned i = 1; i <= max_edge; i++) {
            for (unsigned j = 1; j <= max_edge; j++) {
                acc = vert[i][k] + vert[k][j];
                vert[i][j] = MIN(vert[i][j], acc);
            }
        }
    }

    for (unsigned y = 1; y <= max_edge; y++) {
        for (unsigned x = y + 1; x <= max_edge; x++)
            answer += vert[y][x];
    }
}

void set_infinite(unsigned limit)
{
    for (unsigned y = 1; y <= limit; y++) {
        for (unsigned x = 1; x <= limit; x++) {
            if (x != y) {
                vert[y][x] = INFINITE;
            }
        }
    }
}

int main(void)
{
    unsigned cases;
//    unsigned answer = 0;
    unsigned i, j, w;
    for (unsigned e = 1; e < VERTICES; e++) {
        vert[e][e] = 0;
    }
    set_infinite(VERTICES - 1);

    scanf("%u", &cases);
    cases++;
//    printf("cases = %u\n", cases);
    for (unsigned cnt = 1; cnt < cases; cnt++) {
        scanf("%u", &edges);
        max_edge = 0;
        for (unsigned e = 1; e < edges; e++) {
            scanf("%u %u %u", &i, &j, &w);
            vert[i][j] = vert[j][i] = w;
//            max_edge = MAX(max_edge, i);
            max_edge = MAX(max_edge, j);
        }


//        printf("edges = %u\n", edges);
        solve();
        printf("#%u %u\n", cnt, answer);
/*        for (unsigned x = 1; x <= max_edge; x++) {
            for (unsigned y = 1; y <= max_edge; y++) {
                printf("%u ", vert[x][y]);
            }
            printf("\n");
        }*/

        set_infinite(max_edge);
        answer = 0;
    }

    return 0;
}
