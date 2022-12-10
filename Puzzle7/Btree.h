//
// Created by michal on 09.12.22.
//

#ifndef PUZZLE7_BTREE_H
#define PUZZLE7_BTREE_H

typedef struct Node Node;
typedef struct Queue Queue;
void *appendQueue(Queue *, Node*);
int isQueueEmpty(Queue*);
Node *popQueue(Queue*);
Queue *createQueue();
Node *createNode(int, Node*, char*);
int *createBtree(FILE *fp);
Node *findNameInDir(Node *curNode, char *);
char *getNameCD(char*);
int compareTwoStrings(char *,char*);
//int *searchAlgorithm();

#endif //PUZZLE7_BTREE_H
