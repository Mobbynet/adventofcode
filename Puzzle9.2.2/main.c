#include "rope.h"

#define FILE_READ "/home/michal/Studia/AdventOfCode/Puzzle9.2.2/test.txt"

int main() {
    int (*wasT)[MAP_SIZE];
    wasT = (int (*)[MAP_SIZE]) malloc(MAP_SIZE * MAP_SIZE * sizeof(int));
    Node **Rope;
    Rope = createRope();
    FILE *input;
    input = fopen(FILE_READ, "r");
    char buff[64];
    int moves = 0;
    while (fscanf(input, "%s", buff) != EOF) {
        switch (buff[0]) {
            case 'R':
                fscanf(input, "%s", buff);
                moves = atoi(buff);
                for (int i = 0; i < moves; ++i) {
                    Rope[0]->x += 1;
                    for (int j = 1; j < ROPE_SIZE; j++)
                        MoveNode(Rope[j]);


                    wasT[Rope[ROPE_SIZE - 1]->x][Rope[ROPE_SIZE - 1]->y] = 1;
                    printf("\n%d %d\n", Rope[ROPE_SIZE - 1]->x, Rope[ROPE_SIZE - 1]->y);
                }
                break;

            case 'L':
                fscanf(input, "%s", buff);
                moves = atoi(buff);
                for (int i = 0; i < moves; ++i) {
                    Rope[0]->x -= 1;
                    for (int j = 1; j < ROPE_SIZE; j++)
                        MoveNode(Rope[j]);


                    wasT[Rope[ROPE_SIZE - 1]->x][Rope[ROPE_SIZE - 1]->y] = 1;
                    printf("%d %d\n", Rope[ROPE_SIZE - 1]->x, Rope[ROPE_SIZE - 1]->y);
                }
                break;

            case 'U':
                fscanf(input, "%s", buff);
                moves = atoi(buff);
                for (int i = 0; i < moves; ++i) {
                    Rope[0]->y += 1;
                    for (int j = 1; j < ROPE_SIZE; j++)
                        MoveNode(Rope[j]);


                    wasT[Rope[ROPE_SIZE - 1]->x][Rope[ROPE_SIZE - 1]->y] = 1;
                    printf("%d %d\n", Rope[ROPE_SIZE - 1]->x, Rope[ROPE_SIZE - 1]->y);
                }

                break;

            case 'D':
                fscanf(input, "%s", buff);
                moves = atoi(buff);
                for (int i = 0; i < moves; ++i) {
                    Rope[0]->y -= 1;
                    for (int j = 1; j < ROPE_SIZE; j++)
                        MoveNode(Rope[j]);


                    wasT[Rope[ROPE_SIZE - 1]->x][Rope[ROPE_SIZE - 1]->y] = 1;
                    printf("%d %d\n", Rope[ROPE_SIZE - 1]->x, Rope[ROPE_SIZE - 1]->y);
                }
                break;

        }

    }
    int sum = 0;
    for (int i = 0; i < MAP_SIZE; ++i){
        for (int j = 0; j < MAP_SIZE; ++j) {
            if (wasT[i][j] == 1) {
                sum++;
                printf("#");
            } else {
                printf(".");
            }

        }
        printf("\n");
    }

    printf("Anwser:%d",sum);
    freeRope(Rope);
    free(wasT);
    fclose(input);
    return 0;
}
