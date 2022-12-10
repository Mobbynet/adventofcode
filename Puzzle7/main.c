//
// Created by michal on 09.12.22.
//

#include <stdlib.h>
#include <stdio.h>
#include "Btree.h"


int main(void){
    FILE *input;
    input = fopen("/home/michal/CLionProjects/Puzzle7/input.txt","r");
    if(input == NULL)
        return 0;
    int *output = buildBtree(input);


}
