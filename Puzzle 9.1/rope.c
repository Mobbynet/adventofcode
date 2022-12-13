//
// Created by michal on 12.12.22.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "map.h"


Ropelink *createRopelink(Ropelink *previous_ropelink,int t_x,int t_y){
    Ropelink *new_ropelink = (Ropelink* )malloc(sizeof(Ropelink));
    new_ropelink->x = t_x;
    new_ropelink->y = t_y;
    new_ropelink->nextLink = previous_ropelink;
    return new_ropelink;
}

Ropelink **createRope(int t_x,int t_y,int size_of_rope){
    Ropelink **rope = (Ropelink** )malloc(size_of_rope*sizeof(Ropelink*));
    rope[0] = createRopelink(NULL,t_x,t_y);
    for (int i = 1; i < size_of_rope; ++i) {
        rope[i] = createRopelink(rope[i-1],t_x,t_y);
    }
    return rope;                                       //yyyyyyyyy
}                                                      //123456789

void freeRope(Ropelink **rope, int size_of_rope){      //000000000      x:0
    for (int i = 0; i < size_of_rope; ++i) {           //000000000      x:1
        free(rope[i]);                                 //000X00000      x:2
    }                                                  //000000000      x:3
    free(rope);
}

bool ropeCheck(Ropelink **rope,int link_checked){
    for (int i = 1; i > -2; --i) {
        for (int j = 1; j > -2; --j) {
            if((rope[link_checked]->x+i == rope[link_checked-1]->x) && (rope[link_checked]->y+j == rope[link_checked-1]->y))
                return 1;
        }
    }
    return 0; //if not found return 0
}
void moveRight(Ropelink** rope, Node*** map,int rope_size){
    rope[0]->x += 1;
    int i = 0;
    for (int i = 1; i < rope_size; ++i){
        if(ropeCheck(rope,i) == 0){
            if(i == rope_size-1) {
                map[rope[i]->x][rope[i]->y]->wasT = 1;
            }
            rope[i]->x = rope[i-1]->x - 1;
            rope[i]->y = rope[i-1]->y; // ta czesc kodu przypisuje calemu rope y= rope[0]->y

    }
    }
}
void moveLeft(Ropelink** rope, Node*** map,int rope_size){
    rope[0]->x -= 1;
    for (int i = 1; i < rope_size; ++i) {
        if(ropeCheck(rope,i) == 0){
            if(i == rope_size-1) {
                map[rope[i]->x][rope[i]->y]->wasT = 1;
            }
            rope[i]->x = rope[i-1]->x + 1;
            rope[i]->y = rope[i-1]->y;
        }
    }

}

void moveUp(Ropelink** rope, Node*** map,int rope_size){
    rope[0]->y += 1;
    for (int i = 1; i < rope_size; ++i) {
        if(ropeCheck(rope,i) == 0){
            if(i == rope_size-1) {
                map[rope[i]->x][rope[i]->y]->wasT = 1;
            }
            rope[i]->x = rope[i-1]->x;
            rope[i]->y = rope[i-1]->y - 1;
        }
    }
}
void moveDown(Ropelink** rope, Node*** map,int rope_size){
    rope[0]->y -= 1;
    for (int i = 1; i < rope_size; ++i) {
        if(ropeCheck(rope,i) == 0){
            if(i == rope_size-1) {
                map[rope[i]->x][rope[i]->y]->wasT = 1;
            }
            rope[i]->x = rope[i-1]->x;
            rope[i]->y = rope[i-1]->y + 1;
        }
    }

}

void printRope(Ropelink** rope, int displaySize){
    printf("\n");
    for (int i = 0; i < displaySize; ++i) {
        for (int j = 0; j < displaySize; ++j) {
            for (int k = 0; k < 10; ++k) {
                if(rope[k]->x-32==i && rope[k]->y-32==j)
                    printf("%d",k);
            }
            printf(".");
        }
        printf("\n");
    }


}