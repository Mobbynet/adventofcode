#include <stdio.h>
#include <stdlib.h>

#include "register.h"

#define FILE_READ "/home/michal/Studia/AdventOfCode/Puzzle10.1/input.txt"




int main() {
    Register *regi;
    regi = malloc(sizeof(Register));
    regi->cycle = 0;
    regi->reg[0] = 1;
    FILE *input;
    input = fopen(FILE_READ,"r");
    char buff[16];
    int addx = 0;
    while(fscanf(input,"%s",buff) != EOF){
        switch (buff[0]) {
            case 'n':
                regi->cycle+=1;
                regi->reg[regi->cycle] = regi->reg[regi->cycle-1];
                break;
            case 'a':
                regi->cycle+=1;
                regi->reg[regi->cycle] = regi->reg[regi->cycle-1];
                fscanf(input,"%s",buff);
                addx = atoi(buff);
                regi->cycle+=1;
                regi->reg[regi->cycle] = regi->reg[regi->cycle-1] + addx;
                break;

        }
    }
    //printf("Anwser is: %d,%d",20*regi->reg[19]+60*regi->reg[59]+100*regi->reg[99]+140*regi->reg[139]+180*regi->reg[179]+220*regi->reg[221],regi->cycle);
    printf("\n");
    for(int i = 0; i < 240; i++){
        if(regi->reg[i] == i%40 || (regi->reg[i] + 1) == i%40 || (regi->reg[i] - 1) == i%40)
            printf("#");
        else
            printf(".");

        if((i+1)%40 == 0)
            printf("\n");
    }

    //very fun

    return 0;
}
