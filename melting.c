#include <stdio.h>

#define VERTICES 1008
#define INFINITE 0xffffffff

unsigned vert[VERTICES][VERTICES];

int main(void)
{
    unsigned cases;
//    unsigned answer = 0;
    unsigned i, j, w;
    unsigned edges;
    unsigned len;

    scanf("%u", &cases);
    cases++;
    printf("cases = %u\n", cases);
    for (unsigned cnt = 1; cnt < cases; cnt++) {
        scanf("%u", &edges);
        for (unsigned e = 1; e < edges; e++) {
            scanf("%u %u %u", &i, &j, &w);
            vert[i][j] = vert[j][i] = w;
        }
        printf("edges = %u\n", edges);
        for (unsigned e = 1; e <= edges; e++) {
            vert[e][e] = INFINITE;
        }
        for (unsigned y = 1; y <= edges; y++) {
            for (unsigned x1 = y + 1; x1 < edges; x1++) {
                if (vert[y][x1] == 0) {
                    continue;
                }
                for (unsigned x2 = x1 + 1; x2 <= edges; x2++) {
                    if (vert[y][x2] != 0) {
                        len = vert[y][x1] + vert[y][x2];
                        if (vert[x1][x2] == 0 || len < vert[x1][x2]) {
                            vert[x1][x2] = vert[x2][x1] = len;
                        }
                    }
                }
            }
        }
        for (unsigned y = 1; y <= edges; y++) {
            for (unsigned x1 = y + 1; x1 <= edges; x1++) {
                if (vert[y][x1] == 0) {
                }
            }
        }
//        printf("#%u %u", cnt, answer);
    }
    for (unsigned x = 1; x <= edges; x++) {
        for (unsigned y = 1; y <= edges; y++) {
            printf("%u ", vert[x][y]);
        }
        printf("\n");
    }

    return 0;
}
