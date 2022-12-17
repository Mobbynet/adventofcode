//
// Created by michal on 16.12.22.
//

#include "Queue.h"

//ukradzione z puzzle 7

Queue *createQueue(){
    Queue *newQueue;
    newQueue = (Queue* ) malloc(sizeof(Queue));
    newQueue->q_len = 0;
    //newQueue->queue = (Node**) malloc(sizeof(Node*));
    return newQueue;
}
void *appendQueue(Queue *t_queue, Node *t_node) {
    t_queue->q_len = t_queue->q_len + 1;
    //t_queue =(Node**) realloc(t_queue->queue,t_queue->q_len*sizeof(Node*));
    //int size_of_q = 0;
    //size_of_q = t_queue->q_len;
    for(int i =0; i < t_queue->q_len; i++)
        t_queue->queue[t_queue->q_len - i] = t_queue->queue[t_queue->q_len-1-i];

    //t_queue->q_len = 10;
    t_queue->queue[0] = t_node;
}
Node *popQueue(Queue *t_queue){
    Node *returned_node;
    returned_node = t_queue->queue[0];
    t_queue->q_len = t_queue->q_len -1;
    for(int i = 0; i < t_queue->q_len; i++)
        t_queue->queue[i] = t_queue->queue[i+1];
    t_queue->queue[t_queue->q_len] = NULL;
    //t_queue->queue = (Node**)realloc(t_queue->queue,t_queue->q_len*sizeof(Node*));
    return returned_node;
}
int isQueueEmpty(Queue *t_queue){
    if(t_queue->queue[0] == NULL)
        return 1;

    return 0;
}