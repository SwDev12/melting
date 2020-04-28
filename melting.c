#include <stdio.h>

#define VERTICES 1008

struct v {
    unsigned to;
    unsigned w;
};

struct v table[VERTICES][VERTICES - 1];
unsigned links[VERTICES];

unsigned vertices;

int main(void)
{
    unsigned cases;
    unsigned from, to, weight;
    unsigned idx;

    scanf("%u", &cases);
    cases++;

    for (unsigned i = 1; i < cases; i++) {
        scanf("%u", &vertices);
        for (unsigned v = 1; v < vertices; v++) {
            scanf("%u %u %u", &from, &to, &weight);
            printf("%u %u %u\n", from, to, weight);
            idx = ++links[from];
            table[from][idx].to = to;
            table[from][idx].w = weight;
            idx = ++links[to];
            table[to][idx].to = from;
            table[to][idx].w = weight;
        }
    }

/*    for (unsigned y = 1; y <= vertices; y++) {
        printf("links[%u] = %u\n", y, links[y]);
    }*/

    for (unsigned y = 1; y <= vertices; y++) {
        for (unsigned x = 1; x <= links[y]; x++) {
            printf("[%u, %u] w = %u\n", y, table[y][x].to, table[y][x].w);
        }
        printf("\n");
    }

    return 0;
}
