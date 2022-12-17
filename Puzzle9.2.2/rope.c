//
// Created by michal on 15.12.22.
//
#include "rope.h"


//Data structre creation and removal functions
Node *createNode(int x_t, int y_t,Node* next_node_t){
    Node* newNode;
    newNode = (Node* )malloc(sizeof(Node));
    newNode->x = x_t;
    newNode->y = y_t;
    newNode->next_link=next_node_t;
    return newNode;
}
Node **createRope(){

    Node **newRope; //problem tutaj
    newRope = (Node** )malloc(ROPE_SIZE*sizeof(Node*));
    newRope[0] = createNode(MAP_SIZE/2,MAP_SIZE/2,NULL);
    for (int i = 1; i < ROPE_SIZE; ++i) {
        newRope[i] = createNode(MAP_SIZE/2,MAP_SIZE/2,newRope[i-1]);
    }
    return newRope;

}

void freeRope(Node** rope){
    for (int i = 0; i < ROPE_SIZE; ++i) {
        free(rope[i]);
    }
    free(rope);
}
//Functions to peform algorithms
void MoveNode(Node *m_node){
    if(m_node->next_link == NULL)
        printf(stderr,"Blad we wczytywaniu struktry Node w funkcji moveNode");
    int disX = m_node->next_link->x - m_node->x;
    int disY = m_node->next_link->y - m_node->y;
        if (disX != 0)
            m_node->x += abs(disX)/disX;
        if (disY != 0)
            m_node->y += abs(disY)/disY;


}
