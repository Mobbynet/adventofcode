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
    newNode->neighlen = -1;
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
    for (int i = 0; i < ALPHABET_LEN; ++i)
        if(alphabet[i] == letter)
            return i;

    return 99; //if not found
}



void assignMemoryToPosNeighbours(Node *node_t) {
    if(node_t->neighlen == -1){
        node_t->pos_neighbours = (Node**)malloc(sizeof(Node*));
        if (node_t->pos_neighbours == NULL) {
            printf("Allocation to node: %d %d from NULL to Node** pointer failed", node_t->x, node_t->y);
        }
    }
    else{
        node_t->pos_neighbours = (Node**) realloc(node_t->pos_neighbours,(node_t->neighlen+1)*sizeof(Node*));
        if (node_t->pos_neighbours == NULL) {
                printf("Allocation to node: %d %d from NULL to Node** pointer failed",node_t->x,node_t->y);
            }
    }
}

void checkAndAppendNeighbour(Node* node_t,Node *node_t2){
    if(findAlphIndex(node_t->letter) == 99 || findAlphIndex(node_t2->letter) == 99)
        printf(stderr,"Index of letter not found");
    else if(findAlphIndex(node_t->letter) == findAlphIndex(node_t2->letter)){
        assignMemoryToPosNeighbours(node_t);
        node_t->neighlen++;
        node_t->pos_neighbours[node_t->neighlen] = node_t2;
    }
    else if(findAlphIndex(node_t->letter) == (findAlphIndex(node_t2->letter)-1)){
        assignMemoryToPosNeighbours(node_t);
        node_t->neighlen++;
        node_t->pos_neighbours[node_t->neighlen] = node_t2;
    }

    else if(findAlphIndex(node_t->letter) == (findAlphIndex(node_t2->letter)+ 1)){
        assignMemoryToPosNeighbours(node_t);
        node_t->neighlen++;
        node_t->pos_neighbours[node_t->neighlen] = node_t2;
    }
}


void createNeighbours(Node*** graph_t,int max_x,int max_y){
    for (int i = 0; i < max_y; ++i) {
        for (int j = 0; j < max_x; ++j) {
            if(i==0 && j ==0){
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j+1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i+1][j]);
            }
            else if((i==0) && (j==max_x-1)){
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j-1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i+1][j]);
            }
            else if((i == max_y -1) && (j ==0)){
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j+1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i-1][j]);
            }
            else if((i == max_y -1) && (j == max_x -1)){
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j-1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i-1][j]);
            }
            else if(i == 0){
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j+1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j-1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i+1][j]);
            }
            else if(i == max_y-1){
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j+1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j-1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i-1][j]);
            }
            else if(j == 0){
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j+1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i-1][j]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i+1][j]);
            }
            else if(j == max_x-1){
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j-1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i-1][j]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i+1][j]);
            }
            else{
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j+1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i][j-1]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i-1][j]);
                checkAndAppendNeighbour(graph_t[i][j],graph_t[i+1][j]);

            }
        }
    }

}
void freeGraph(Node*** graph_t,int max_x,int max_y){
    for(int32_t i; i < max_x;++i){
        for(int j = 0; j < max_y; ++j) {
            free(graph_t[i][j]);
        }

    }

}