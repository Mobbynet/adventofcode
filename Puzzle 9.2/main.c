#include <stdio.h>
#include <stdlib.h>

#include "map.h"

#define MAP_SIZE 512
#define ROPE_SIZE 10
#define FILE_READ "/home/michal/Studia/AdventOfCode/Project 9.1v2/input.txt"

int main() {
    printf("Hello, World!\n");
    Node ***map;
    map = initMap(MAP_SIZE);
   // printf("%d %d",map[1][2]->x,map[1][2]->wasT);
    Ropelink **rope;
    rope = createRope(MAP_SIZE/2-1,MAP_SIZE/2-1,ROPE_SIZE);
    //printf(" %d %d %d",rope[1]->nextLink->x,rope[2]->nextLink->x,rope[3]->nextLink->nextLink->x);
    //Po stowrzeniu struct Rope zorientowalem sie ze nie potrzebuje tej mapy(trudniej bedzie z liczeniem tego ale co ja zrobie takie zycie), ale tyle sie meczylem by nie miec z nia segmentation fault ze juz w sumie zostanie
    FILE *input;
    input = fopen(FILE_READ,"r");
    char buff[3];
    int moves = 0;
    while(fscanf(input,"%s",buff) != EOF){ //to wczytywanie danych jest glupie ale dziala dobrze wiec nie bede tego zmienial
        switch (buff[0]) {
            case 'R':
                fscanf(input,"%s",buff);
                moves = atoi(buff);
                for (int i = 0; i < moves; ++i) {
                    moveRight(rope[ROPE_SIZE-1],map,ROPE_SIZE-1);

                }
                break;
            case 'L':
                fscanf(input,"%s",buff);
                moves = atoi(buff);
                for (int i = 0; i < moves; ++i) {
                    moveLeft(rope[ROPE_SIZE-1],map,ROPE_SIZE-1);

                }
                break;
            case 'U':
                fscanf(input,"%s",buff);
                moves = atoi(buff);
                for (int i = 0; i < moves; ++i) {
                    moveUp(rope[ROPE_SIZE-1],map,ROPE_SIZE-1);

                }
                break;
            case 'D':
                fscanf(input,"%s",buff);
                moves = atoi(buff);
                for (int i = 0; i < moves; ++i) {
                    moveDown(rope[ROPE_SIZE-1],map,ROPE_SIZE-1);

                }
                break;
        }


    }
    map[rope[ROPE_SIZE-1]->x][rope[ROPE_SIZE-1]->y]->wasT = 1; //ostatnia pozycja nie jest zapisana

    printf("\n Answer is: %d \n", countWasT(map,MAP_SIZE));
    freeMap(map,MAP_SIZE);
    freeRope(rope,ROPE_SIZE);
    fclose(input);
    return 0;
}
