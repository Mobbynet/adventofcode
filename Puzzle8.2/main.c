#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#define FILE_READ "/home/michal/Studia/AdventOfCode/Puzzle8.2/input.txt"



int main() {
    FILE *input;
    input = fopen(FILE_READ, "r");
    int **nums;
    int *temp;
    char buff[512];
    int size_x = 0;
    int size_y = 0;
    while (fscanf(input, "%s", buff) != EOF) {
        size_y = 0;
        while (buff[size_y] != '\0')
            size_y++;
        size_x++;
    }
    fclose(input);
    input = fopen(FILE_READ, "r");
    int (*trees)[size_x];
    trees = (int (*)[size_x]) malloc(size_x * (size_y + 1) * sizeof(int));
    int (*vis_tree)[size_x];
    vis_tree = (int (*)[size_x]) malloc(size_x * (size_y + 1) * sizeof(int));
    /*for (int p = 0; p < size_x; p++) {
        for (int l = 0; l < size_y; l++){
            vis_tree[p][l] = 0;
        }
    }*/
    int i = 0;
    int w = 0;
    char in;



    for (int j = 0; j < size_x; ++j) {
        for (int k = 0; k < size_y; ++k) {
            in = fgetc(input);
            trees[j][k] = in - '0';
            printf("%d ", trees[j][k]);
        }
        in = fgetc(input);
        printf("\n");
    }


    //printf("\n\n\n\n");
    for (int j = 0; j < size_x; ++j) {
        for (int k = 0; k < size_y; ++k) {
            vis_tree[j][k] = 1;
            //printf("%d ",vis_tree[j][k]);
        }
        //printf("\n");
    }
   int sum = 0;
    int currentMax;
    i = 0;
    for (int j = 0; j < size_x; ++j) {
        for (int k = 0; k < size_y; ++k) {
            currentMax = trees[j][k];
            if(j < size_x) { //liczy zle //no tak //brakowalo +1 przy warunku j+i + 1 <size_x //nwm czemu ta 1 ma tam byc ale kiedys pewnie zrozumiem
                sum = 0;
                i = 0;
                do {
                    sum++;
                    i++;
                } while (trees[j + i][k] < currentMax && j + i + 1< size_x);

                vis_tree[j][k] = vis_tree[j][k] * sum;
            }
            if(j > 0) {
                sum = 0; //tu napewno jest blad //jednak nie bylo
                i = 0;
                do {
                    sum++;
                    i--;
                } while (trees[j + i][k] < currentMax && j + i > 0);

                vis_tree[j][k] = vis_tree[j][k] * sum;
            }
            if(k < size_y) {
                    sum = 0;
                    i = 0;
                    do {
                        sum++;
                        i++;
                    } while (trees[j][k+i] < currentMax && k + i + 1< size_y);

                    vis_tree[j][k] = vis_tree[j][k] * sum;
                }
            if(k > 0) {
                    sum = 0;
                    i = 0; //tu jest blad XDD
                    do {
                        sum++;
                        i--;
                    } while (trees[j][k+i] < currentMax && k+ i > 0);

                    vis_tree[j][k] = vis_tree[j][k] * sum;
            }
        }
    }
    printf("\n\n\n");

    int max = -1;
    for (int j = 0; j < size_x; ++j) {
        for (int k = 0; k < size_y; ++k) {
            if(vis_tree[j][k] > max)
                max = vis_tree[j][k];
            printf("%d ",vis_tree[j][k]);
            }
        printf("\n");
        }


    printf("\n%d",max);
}