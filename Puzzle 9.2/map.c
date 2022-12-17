//
// Created by michal on 12.12.22.
//
#include <stdlib.h>
#include <stdio.h>



#include "map.h"



Node *createNode(int t_x, int t_y){
    Node *newNode;
    newNode = (Node* )malloc(sizeof(Node));
    newNode-> x = t_x;
    newNode-> y = t_y;
    newNode-> wasT = 0;
    return newNode;
}
Node ***initMap(int map_size){
    Node ***new_map = (Node*** )malloc(map_size*sizeof(Node**));
    for (int i = 0; i < map_size; ++i) {
        new_map[i] = (Node** )malloc(map_size*sizeof(Node*));
    }
    for (int i = 0; i < map_size; ++i)
        for (int j = 0; j < map_size; ++j) {
            new_map[i][j] = createNode(i,j);
        }
    return new_map;
}
void freeMap(Node ***map,int map_size){
    for (int i = 0; i < map_size; ++i) {
        for (int j = 0; j < map_size; ++j) {
            free(map[i][j]);
        }
        free(map[i]);
    }
    free(map);
}
int countWasT(Node*** map,int map_size){
    int sum = 0;
    for (int i = 0; i < map_size; ++i) {
        for (int j = 0; j < map_size; ++j) {
            if(map[i][j]->wasT == 1)
                sum++;
        }
    }
    return sum;
}