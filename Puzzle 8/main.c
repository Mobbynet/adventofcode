#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

int main() {
    FILE *input;
    input = fopen("/home/michal/Studia/AdventOfCode/Puzzle 8/input.txt","r");
    int **nums;
    int *temp;
    char buff[512];
    int size_x = 1;
    int size_y = 0;
    while(fscanf(input,"%s",buff) != EOF){
        size_y = 0;
        while(buff[size_y] != '\0')
            size_y++;
        size_x++;
    }
    fclose(input);
    input = fopen("/home/michal/Studia/AdventOfCode/Puzzle 8/input.txt","r");
    int (*trees)[size_x];
    trees = (int(*)[size_x]) malloc(size_x*size_y*sizeof(int));
    int (*vis_tree)[size_x];
    vis_tree = (int(*)[size_x]) malloc(size_x*size_y*sizeof(int));
    /*for (int p = 0; p < size_x; p++) {
        for (int l = 0; l < size_y; l++){
            vis_tree[p][l] = 0;
        }
    }*/
    int i = 0;
    int w = 0;

    while(fscanf(input,"%s",buff) != EOF){
        w = 0;
            while(buff[w] != '\0'){
             trees[i][w] = buff[w] - '0';
             w++;
            }
            i++;
    }
    printf("%d %d",size_x,size_y);

    int x = 0;
    int y = 0;
    int current_max = -1;
    for(int j = 0; j < size_x;j++) { // LEWO y="0"
        x = j;
        y = 0;
        current_max = -1;
        while(y < size_y){
        if(trees[x][y] > current_max){
            current_max = trees[x][y];
            vis_tree[x][y] = 1;
        }
        /*else if(vis_tree[x][y] != 1)
            vis_tree[x][y] = 0; */
        y++;
        }
        current_max = -1;
    }

    x = 0;
    y = 0;
    y = size_y-1;
    current_max = -1;
    for(int j = 0; j < size_x-1;j++) { // PRAWO y="size_y"
        x = j;
        y = size_y-1;
        current_max = -1;
        while(y >= 0){
        if(trees[x][y] > current_max){
            current_max = trees[x][y];
            vis_tree[x][y] = 1;
        }
        /*else if(vis_tree[x][y] != 1)
            vis_tree[x][y] = 0; */
        y--;
        }
        current_max = -1;
    }

        x = 0;
        y = 0;
     current_max = -1;
    for(int j = 0; j < size_y;j++) { // GORA X=""
        y = j;
        x = 0;
        current_max = -1;
        while(x < size_x-1){
        if(trees[x][y] > current_max){
            current_max = trees[x][y];
            vis_tree[x][y] = 1;
        }
        /* else if(vis_tree[x][y] != 1)
            vis_tree[x][y] = 0; */
        x++;
        }
        current_max = -1;
    }

     x = 0;
    y = 0;
    x = size_x-1;
    current_max = -1;
    for(int j = 0; j < size_y;j++) { // DOL y="size_y"
        y = j;
        x = size_x-1;
        current_max = -1;
        while(x >= 0){
            if(trees[x][y] > current_max){
                current_max = trees[x][y];
                vis_tree[x][y] = 1;
            }
            x--;
        }
        current_max = -1;
    }
    int sum = 0;
    printf("\n");
    for(int g = 0; g < size_x; g++){
        for(int t = 0; t < size_y;t++){
            if(vis_tree[g][t] == 1)
                sum++;
            printf("%d",vis_tree[g][t]);
        }
        printf("\n");
    }
    printf("%d",sum);

}
