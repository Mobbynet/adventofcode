#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

int main() {
    FILE *input;
    input = fopen("/home/michal/Studia/AdventOfCode/Puzzle 8/input.txt", "r");
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
    input = fopen("/home/michal/Studia/AdventOfCode/Puzzle 8/input.txt", "r");
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
        fscanf(input, "%s", buff);
        for (int k = 0; k < size_y; ++k) {
            trees[j][k] = buff[k] - 48;
        }
    }

    for (int j = 0; j < size_x; ++j) {
        for (int k = 0; k < size_y; ++k) {
            printf("%d ", trees[j][k]);
        }
        printf("\n");
    }
    int sum = 0;
    int currentMax;
    for (int j = 0; j < size_x; ++j) { // lewo
        currentMax = -1;
        for (int k = 0; k < size_y; ++k) {
            if (trees[j][k] > currentMax) {
                printf("%d > %d \n", trees[j][k],currentMax);
                currentMax = trees[j][k];
                vis_tree[j][k] = 1;
            }

        }
    }


    for (int j = 0; j < size_y; ++j) { // gora
        currentMax = -1;
        for (int k = 0; k < size_x; ++k) {
            if (trees[k][j] > currentMax) {
                printf("%d > %d \n", trees[k][j],currentMax);
                currentMax = trees[k][j];
                vis_tree[k][j] = 1;
            }

        }
    }
    for (int j = 0; j < size_x; ++j) { // prawo
        currentMax = -1;
        for (int k = size_y-1; k >= 0; --k) {
            if (trees[j][k] > currentMax) {
                printf("%d > %d \n", trees[j][k],currentMax);
                currentMax = trees[j][k];
                vis_tree[j][k] = 1;
            }

        }
    }
    for (int j = 0; j < size_y; ++j) { // dol
        currentMax = -1;
        for (int k = size_x-1; k >= 0; --k) {
            if (trees[k][j] > currentMax){
                printf("%d > %d \n", trees[k][j],currentMax);
                currentMax = trees[k][j];
                vis_tree[k][j] = 1;
            }

        }
    }

    for (int j = 0; j < size_x; ++j) {
        for (int k = 0; k < size_y; ++k) {
            printf("%d",vis_tree[j][k]);
            if (vis_tree[j][k] == 1) {
                sum++;
            }
        }
        printf("\n");
    }
    printf("\n%d",sum);
}