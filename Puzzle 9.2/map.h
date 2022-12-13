//
// Created by michal on 12.12.22.
//

#ifndef PROJECT_9_1V2_MAP_H
#define PROJECT_9_1V2_MAP_H

#include <stdbool.h>
#include "rope.h"

typedef struct Node Node;
struct Node{
    int x;
    int y;
    int wasT;
};
Node*createNode(int,int);
Node***initMap(int);
void freeMap(Node***,int);
void moveRight(Ropelink*, Node***,int);
void moveLeft(Ropelink*, Node***,int);
void moveUp(Ropelink*, Node***,int);
void moveDown(Ropelink*, Node***,int);
bool ropeCheck(Ropelink*,int, Node***);
int countWasT(Node***,int);
#endif //PROJECT_9_1V2_MAP_H
