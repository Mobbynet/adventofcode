//
// Created by michal on 16.12.22.
//

#include "Node.h"

#define ALPHABET_LEN 26

const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";


Node *createNode(int y_t,int x_t){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf(stderr,"Allocation of new memory for newNode %d %d failed",x_t,y_t);
        return 1;
    }
    newNode->x = x_t;
    newNode->y = y_t;//neighbours is empty as is char
    newNode->neightailloc = -1;
    newNode->visited = 0;
    //newNode ->pos_neighbours = NULL;
    return newNode;
}
Node ***createGraph(char **mapa,int x,int y) {
    Node ***Graph;
    if (Graph == NULL) {
        printf(stderr,"Allocation of new memory for Graph  failed");
        return 1;
    }
    Graph = (Node***) malloc(x*sizeof(Node**));
    for (int i = 0; i < x; ++i) {
        Graph[i] = (Node**) malloc(y*sizeof(Node*));
    }
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) {
            Graph[i][j] = createNode(i, j);
            Graph[i][j]->letter = mapa[i][j];
            //printf("%d      %d  %d \n", Graph[0][0]->x , x, y);

        }
    }
    return Graph;

}
int findAlphIndex(char letter){
    if(letter == 'S'){
        return 0;
    }
    else if(letter == 'E'){
        return ALPHABET_LEN-1;
    }
    else {
        for (int i = 0; i < ALPHABET_LEN; ++i)
            if (alphabet[i] == letter)
                return i;
    }
    return 99; //if not found
}




bool IsInMap(int y_t, int x_t,int max_y_t,int max_x_t) {
    if (y_t > max_y_t-1 || y_t < 0)
        return 0;
    else if (x_t > max_x_t-1 || x_t < 0)
        return 0;
    else
        return 1;
}


void checkAndAppendNeighbour(Node* node_t,Node *node_t2){
    if(findAlphIndex(node_t->letter) == 99 || findAlphIndex(node_t2->letter) == 99)
        printf(stderr,"Index of letter not found");
    if(findAlphIndex(node_t->letter) == findAlphIndex(node_t2->letter)){
        node_t->neightailloc++;
        node_t->pos_neighbours[node_t->neightailloc] = node_t2;
    }
    if(findAlphIndex(node_t->letter) == (findAlphIndex(node_t2->letter)-1)){
        node_t->neightailloc++;
        node_t->pos_neighbours[node_t->neightailloc] = node_t2;
    }
    if(findAlphIndex(node_t->letter) > (findAlphIndex(node_t2->letter))){
        node_t->neightailloc++;
        node_t->pos_neighbours[node_t->neightailloc] = node_t2;
    }
}


void createNeighbours(Node*** graph_t,int max_x,int max_y){
    for (int i = 0; i < max_y; ++i) {
        for (int j = 0; j < max_x; ++j) {
            if(IsInMap(i-1,j,max_y,max_x)){     //UP
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i-1][j]);
            }
            if(IsInMap(i+1,j,max_y,max_x)){     //DOWN
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i+1][j]);
            }
            if(IsInMap(i,j+1,max_y,max_x)){     //RIGHT
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j+1]);
            }
            if(IsInMap(i,j-1,max_y,max_x)){     //LEFT
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j-1]);
            }

        }
    }

}

void freeGraph(Node*** graph_t,int max_x,int max_y){
    for(int32_t i; i < max_y;++i){
        for(uint32_t j = 0; j < max_x; ++j) {
            //free(graph_t[i][j]);
        }
        //free(graph_t[i]);
    }
    free(graph_t);
}