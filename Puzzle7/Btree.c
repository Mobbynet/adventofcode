//
// Created by michal on 09.12.22.
//
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>

#include"Btree.h"

#define SIZE_AVAIABLE 70000000
#define SIZE_NEED 30000000


#define MAX 128





struct Node{
    int size, layer;
    int count;
    Node *dirs[MAX + 1];
    Node *parent;
    char *name;
};
struct Queue{
    Node *queue[MAX+1];
    int q_len;
};
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



Node *createNode(int t_size, Node *t_parent, char *t_name) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->size = t_size;
    newNode->parent = t_parent;
    newNode->name = t_name;
    newNode->layer = t_parent->layer+1;
    newNode->count = -1;
    t_parent->count= t_parent->count +1;
    t_parent->dirs[t_parent->count] = newNode;
    return newNode;
}

Node *findNodeInDir(Node* curNode, char *t_name){
//Name looks like this:
//"rtv.cjj"
//"wjgh"
//"vmypf"
//We get those names form another function getName(buff) which will get as an output of this kinds.
char *name_dir; //we get this name from dir of currentNode
for(int i = 0;i < curNode->count+1; i++){
    name_dir = (curNode->dirs[i])->name;
    if(compareTwoStrings(t_name,name_dir) == 1)
        return curNode->dirs[i];
    }
    return NULL; //if not found return NULL
}

char *getNameCD(char *buff_t){
    unsigned size_of_name = 0; // i = 6 beacuse name starts from 6th charcter
    do size_of_name++;
    while(buff_t[size_of_name+5] != '\0');

    char *name = malloc((size_of_name+1)*sizeof(char));
    for(int i = 0; i < size_of_name;i++)
        name[i] = buff_t[i+5];
    return name;
}
int compareTwoStrings(char *c1,char *c2){
    int i = 0;
    while(c1[i] != '\0' ) {
        if (c1[i] != c2[i])
            return 0;
        i++;
    }
    return 1;
}

Node *createRoot() {
    Node *root;
    root = (Node*)malloc(sizeof(Node));
    root->size = 0;
    root->parent = NULL;
    root->name = "/";
    root->layer = 0;
    root->count = -1;
    return root;
}
int *buildBtree(FILE *fp){
    Node *currentNode = NULL;
    Node *root;
    Node *newNode;
    root =  createRoot();
    char *buff;
    buff = malloc(64*sizeof(char));
    while(fscanf(fp,"%s",buff) !=EOF){
        newNode = NULL;
        printf("%s",buff);
        if(buff[0] == '$')
        {
            fscanf(fp,"%s",buff);
            printf("%s",buff);
            if(buff[0] == 'c'){
                    fscanf(fp,"%s",buff);
                    if(buff[0] == '/')
                        currentNode = root;
                    else if (buff[0] == '.') {
                        currentNode = currentNode->parent;
                    }
                    else {
                    currentNode = findNodeInDir(currentNode,buff);
                }
            }
            //free(buff);
        }
        else if (buff[0] =='d' && buff[1] =='i' && buff[2] == 'r')  {
            fscanf(fp, "%s", buff);
            if(findNodeInDir(currentNode,buff) == NULL)
                newNode = createNode(0,currentNode,buff);
            //currentNode->dirs[currentNode->count] = newNode;
        }
        else{
            currentNode->size = currentNode->size + atoi(buff);
            Node *tempNode;
            if(currentNode->parent != NULL) {
                tempNode = currentNode->parent;
                for (int i = currentNode->layer; i > 0; i--) {
                    tempNode->size = tempNode->size+atoi(buff);
                    tempNode = tempNode->parent;
                    //if (tempNode->name[0] == '/' && i != 0)
                       // printf("BLAD W PRZYDZIELANIU WIELKOSCI DIRS");
                }
                free(tempNode);
            }
            fscanf(fp,"%s",buff);
        }
        buff = malloc(64*sizeof(char));
    }
    Node *temp = root;
    Queue *m_queue;
    m_queue = createQueue();
    int *list;
    int p_size = 1;
    list = malloc(sizeof(int));
    int size_of_directory = SIZE_AVAIABLE;
    do{

        for(int i = 0; i <temp->count+1;i++){
            if((temp->dirs[i])->size < 100000) {
                p_size++;
                list = realloc(list, p_size * sizeof(int));
                list[p_size - 2] = (temp->dirs[i])->size;
            }
            if((temp->dirs[i])->size < size_of_directory) {
                if (temp->dirs[i]->size >= (root->size - (SIZE_AVAIABLE-SIZE_NEED)))
                    size_of_directory = (temp->dirs[i])->size;
            }
            appendQueue(m_queue,temp->dirs[i]);

        }
        temp = popQueue(m_queue);
    }while(!isQueueEmpty(m_queue));
    printf("\nSize Of list:%d \n",p_size);
    int x = 0;
    for (int i = 0; i < p_size; ++i) {
        x = x + list[i];
        printf("%d ", list[i]);
    }
    printf("\nx: %d",x);
    printf("\ny %d",size_of_directory);
    return list;

}
/*
int *searchAlgorithm(Node *root){
    Node *temp;
    temp = root;
    Queue *m_queue;
    m_queue = createQueue();
    int *list;
    int p_size = 1;
    list = malloc(sizeof(int));
    do{
         list = realloc(list,p_size*sizeof(int));
            for(int i = 0; i <temp->count;i++){
                if((temp->dirs[i])->size < 100000){
                    list[p_size-1] = list[p_size] + (temp->dirs[i])->size;
                    appendQueue(m_queue,temp->dirs[i]);
                }
            }
            temp = popQueue(m_queue);
        p_size++;
    }while(!isQueueEmpty(m_queue));
    printf("SizeOf list:%d \n",p_size);
    return list;
}

*/




