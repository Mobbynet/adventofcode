//
// Created by michal on 15.12.22.
//

#ifndef PUZZLE9_2_2_ROPE_H
#define PUZZLE9_2_2_ROPE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


#define MAP_SIZE 512
#define ROPE_SIZE 8


struct Node{
    int x;
    int y;
    struct Node* next_link;
};
typedef struct Node Node;

Node *createNode(int , int ,Node*);
Node **createRope();


void freeRope(Node**);


void MoveNode(Node*);



#endif //PUZZLE9_2_2_ROPE_H
