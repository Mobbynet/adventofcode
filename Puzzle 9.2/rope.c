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
    new_ropelink->previousLink = previous_ropelink;
    return new_ropelink;
}

Ropelink **createRope(int t_x,int t_y,int size_of_rope){
    Ropelink **rope = (Ropelink** )malloc(size_of_rope*sizeof(Ropelink*)); //0 jest ostatnie, ROPE_SIZE - 1 jest pierwsze
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

bool ropeCheck(Ropelink *rope,int link_checked, Node ***map){
    if(link_checked == 0){
        map[rope->x][rope->y]->wasT = 1;
        return 0;
    }

    for (int i = 1; i > -2; --i) {
        for (int j = 1; j > -2; --j) {
            if((rope->x+i == rope->previousLink->x) && (rope->y+j == rope->previousLink->y))
                return 1;
        }
    }
    return 0; //if not found return 0
}
void moveRight(Ropelink* rope_link, Node*** map,int rope_num){
    rope_link->x +=1;
    if(rope_num < 0){}
    else if(ropeCheck(rope_link,rope_num,map) == 0){
        rope_link->previousLink->y = rope_link->y;
        moveRight(rope_link->previousLink,map,rope_num - 1);
    }
}
void moveLeft(Ropelink* rope_link, Node*** map,int rope_num){
    rope_link ->x -= 1;
    if(rope_num < 0){}
    else if(ropeCheck(rope_link,rope_num,map) == 0){
        rope_link->previousLink->y = rope_link->y;
        moveLeft(rope_link->previousLink,map,rope_num - 1);
    }
}

void moveUp(Ropelink* rope_link, Node*** map,int rope_num){
    rope_link->y -=1;
    if(rope_num < 0){}
    else if(ropeCheck(rope_link,rope_num,map) == 0){
        rope_link->previousLink->y = rope_link->x;
        moveUp(rope_link->previousLink,map,rope_num - 1);
    }
}
void moveDown(Ropelink* rope_link, Node*** map,int rope_num){
    rope_link->y -= 1;
    if(rope_num < 0){}
    else if(ropeCheck(rope_link,rope_num,map) == 0){
        rope_link->previousLink->y = rope_link->x;
        moveDown(rope_link->previousLink,map,rope_num - 1);

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