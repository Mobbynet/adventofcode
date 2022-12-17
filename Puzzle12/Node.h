//
// Created by michal on 16.12.22.
//

#ifndef PUZZLE12_NODE_H
#define PUZZLE12_NODE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>



struct Node{
int x;
int y;
struct Node **pos_neighbours; //possible neighbours means that it has edge with it
int neighlen;
char letter;
};

typedef struct Node Node;

Node *createNode(int ,int );
Node ***createGraph(char **,int ,int );
void createNeighbours(Node***,int ,int );
void freeGraph(Node***,int ,int );
void assignMemoryToPosNeighbours(Node *);


#endif //PUZZLE12_NODE_H
