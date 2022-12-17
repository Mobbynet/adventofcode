//
// Created by michal on 16.12.22.
//

#ifndef PUZZLE12_QUEUE_H
#define PUZZLE12_QUEUE_H

#include "Node.h"

#define MAX 256

struct Queue{
    Node *queue[MAX+1];
    int q_len;
};
typedef struct Queue Queue;

void *appendQueue(Queue *, Node *);

Node *popQueue(Queue *);

int isQueueEmpty(Queue *);


#endif //PUZZLE12_QUEUE_H
