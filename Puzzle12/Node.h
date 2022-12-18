//
// Created by michal on 16.12.22.
//

#ifndef PUZZLE12_NODE_H
#define PUZZLE12_NODE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NEIGH 4

struct Node{
int x;
int y;
struct Node *pos_neighbours[MAX_NEIGH]; //possible neighbours means that it has edge with it
int neightailloc;
char letter;
int visited;
};

typedef struct Node Node;

bool IsInMap(int,int,int,int);

Node *createNode(int ,int );
Node ***createGraph(char **,int ,int );
void createNeighbours(Node***,int ,int );
void freeGraph(Node***,int ,int );



#endif //PUZZLE12_NODE_H
