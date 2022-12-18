//
// Created by michal on 16.12.22.
//

#include "Queue.h"

typedef struct {
    Node **data;
    int front;
    int rear;
} queue;

void init(queue *q_t) {
    q_t->data = malloc(MAX_QUEUE_SIZE*sizeof(Node*));
    q_t->front = 0;
    q_t->rear = 0;
}

bool is_empty(queue *q) {
    return q->front == q->rear;
}

void enqueue(queue *q, Node *added_node) {
    q->data[q->rear] = added_node;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

Node* dequeue(queue *q) {
    Node *x = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return x;
}

int BFS(Node ***nodes, int start_x, int start_y, int end_x, int end_y) {
    queue *q = malloc(sizeof(queue));
    init(q);
    Node *start = nodes[start_y][start_x];
    start->visited = 1;
    enqueue(q, start);
    Node *neighbor;
    Node *curr;
    while (!is_empty(q)) {
        curr = dequeue(q);

        if (curr->x == end_x && curr->y == end_y) {
            return curr->visited-1; //start nie liczy sie do krokow
        }
        for (int i = 0; i < curr->neightailloc + 1; i++) {
            neighbor = curr->pos_neighbours[i];
            if (neighbor != NULL && !neighbor->visited) {
                neighbor->visited = curr->visited + 1;
                enqueue(q, neighbor);
            }
        }
    }
    return -1; //not found
}