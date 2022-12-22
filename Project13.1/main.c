#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



#define MAX_LIST 512
#define MAX_STACK 32
#define FILE_READ "/home/michal/Studia/AdventOfCode/Puzzle13/input.txt" //[[8],[7,2,10]]

#define SET_BIT(x, pos) (x |= (1U << pos))
#define CLEAR_BIT(x,pos) (x &= (~(1U << pos))
#define CHECK_BIT(x,pos) (x & (1UL << pos)



typedef struct List List;
struct List{
    unsigned int isNum; //Zakladamy tutaj ze nie bedzie wiecej niz 32 list w jednej lisice
    int num[MAX_LIST];
    int num_len;
    List **childList; //children
    int childListLen;
    List *parList;  //parent list
};

List *createList(List *parentList){
    List *newList = (List *)malloc(sizeof(List ));
    if(newList == NULL)
        printf("Error: NewList is set NULL!");
    newList->isNum = 0x00;
    newList->parList = parentList;
    newList->num_len = 0;
    newList->childListLen = 0;
    newList->childList  = (List** )malloc(sizeof(List*));
    if(newList->childList == NULL)
        printf("Warning! newList->childList is set to NULL");
    for (int i = 0; i < MAX_STACK; ++i) {
        newList->childList[i] = (List *)malloc(sizeof(List));
        if(newList->childList == NULL){
            printf("Warning! newList->childList[%d] is set to NULL",i);
        }
    }
    if(parentList != NULL){
        parentList->childList[parentList->childListLen] = newList;
        parentList->childListLen++;
    }
    else{
        printf("Creating list with NULL parent \n");
    }
    return newList;
}

int compareTwoLists(List *leftList, List *rightList){




}







int main() {
    FILE *input;
    input = fopen(FILE_READ,"r");
    char buff[512];
    List *leftList = createList(NULL);
    List *rightList = createList(NULL);
    char buff_t;
    int i = 0;
    char num_buff[8];
    int curr_index;
    int j =0;
    List *currentList;
    while(fscanf(input,"%s",buff) != EOF){
        i = 0;
        j = 0;
        buff_t=buff[i];
        currentList = leftList;
        curr_index = -1;
        while(buff_t != '\0') {
            if (buff_t == '[') {
                curr_index++;
                currentList = createList(currentList);
                curr_index = 0;
            } else if (buff_t == ']')
                currentList = currentList->parList;

            else if (buff_t == ',' && j != 0) {
                num_buff[j + 1] = '\0';
                curr_index++;
                SET_BIT(currentList->isNum, curr_index);
                currentList->num[curr_index] = atoi(num_buff);
                j = 0;
            } else if (buff_t != ',') {
                num_buff[j] = buff_t;
                j++;
            }


            i++;
            buff_t = buff[i];
        }
        if(fscanf(input,"%s",buff) == EOF){
           printf("Loading file error\n");
            return 1;
        }
        i = 0;
        j = 0;
        buff_t=buff[i];
        currentList = rightList;
        curr_index = -1;
        while(buff_t != '\0') {
            if (buff_t == '[') {
                curr_index++;
                currentList = createList(
                        currentList);// i nie odpowiada danemj komorce w liscie a tylko wylacznie miejscu w bufferze, nalezy utworzyc liczbe ktora bedzie odpowadac temu XDD
                curr_index = 0;
            } else if (buff_t == ']')
                currentList = currentList->parList;

            else if (buff_t == ',' && j != 0) {
                num_buff[j + 1] = '\0';
                curr_index++;
                SET_BIT(currentList->isNum, curr_index);
                currentList->num[curr_index] = atoi(num_buff);
                j = 0;
            } else if (buff_t != ',') {
                num_buff[j] = buff_t;
                j++;
            }


            i++;
            buff_t = buff[i];
        }
        if(fscanf(input,"%s",buff) == EOF){
            printf("Loading file error\n");
            return 1;
        }
    }

    fclose(input);
    return 0;
}
