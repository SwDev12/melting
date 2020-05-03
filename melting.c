#include <stdio.h>

#define VERTICES 1008

struct v {
    unsigned to;
    unsigned w;
};

struct v table[VERTICES][VERTICES - 1];
unsigned links[VERTICES];
unsigned visited[VERTICES];

unsigned vertices;
unsigned answer;

struct elem {
    unsigned to;
    unsigned len_to_source;
} stack_elem[VERTICES];
unsigned stack_top;
struct v tmp;

void solving(void)
{
    struct elem put, get;
    answer = 0;

    for (register unsigned v = 1; v <= vertices; v++) {
        put.to = v; put.len_to_source = 0;
        visited[v] = 1;
        stack_elem[stack_top++] = put;
        while (stack_top != 0) {
            get = stack_elem[--stack_top];
//            printf("take hall %u, stack_top = %u\n", get.to, stack_top);
            for (register unsigned edges = 0; edges < links[get.to]; edges++) {
                tmp = table[get.to][edges];
//                printf("candidate to = %u\n", tmp.to);
                if (visited[tmp.to] == 0) {
                    put.to = tmp.to;
                    put.len_to_source = get.len_to_source + tmp.w;
                    visited[put.to] = 1;
                    stack_elem[stack_top++] = put;
//                    if (v < put.to) {
                        answer += put.len_to_source;
//                    }
//                    printf("load next %u, stack_top = %u, path to sourcce = %u\n", put.to, stack_top, put.len_to_source);
                }
            }
//            printf("\tfinish for %u\n", get.to);
        }
        for (register unsigned x = 1; x <= vertices; x++) {
            visited[x] = 0;
        }
    }
    answer /= 2;
    stack_top = 0;
}

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
//            printf("%u %u %u\n", from, to, weight);
            idx = links[from]++;
            table[from][idx].to = to;
            table[from][idx].w = weight;
            idx = links[to]++;
            table[to][idx].to = from;
            table[to][idx].w = weight;
        }
        solving();
        printf("#%u %u\n", i, answer);
        for (unsigned y = 1; y <= vertices; y++) {
            links[y] = 0;
        }
    }

/*    for (unsigned y = 1; y <= vertices; y++) {
        printf("links[%u] = %u\n", y, links[y]);
    }*/

/*    for (unsigned y = 1; y <= vertices; y++) {
        for (unsigned x = 0; x < links[y]; x++) {
            printf("[%u, %u] w = %u\n", y, table[y][x].to, table[y][x].w);
        }
        printf("\n");
    }*/

    return 0;
}
