#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "Node.h"
#include "Queue.h"
#define FILE_READ "/home/michal/Studia/AdventOfCode/Puzzle12/input.txt"







//Ilosc energetykow wypitych:3
/* Algorytm BFS, wczytywanie danych a nastepnie nalezy ustalic edge miedzy nodeami,kazda litera to odzielnny node, node sa dwukierunkowe(to chyba teoria graphow*/
/* podczas tworzenia graphu, ustalic dwa nody:node_s ==start(S), node_e == end(E)*/
/* w ustalaniu chodzi o zdobycie adresow tych nodow*/
/* maksymalna ilosc edgow w nodzie:4 */

int main() {
    FILE *input;
    input = fopen(FILE_READ,"r");
    int x = 0;
    int y = 0;
    char buff = '0';
    do {
        buff = fgetc(input);            //TODO: Node *visted, Node *prev, createGraph(createVertices, createEdges)
        x++;                            //TODO: int reconstructPath(s,e,prev)
    } while (buff !='\n');
    y++;
    char buff_t[256];
    while(fscanf(input,"%s",buff_t) != EOF)
        y++;
    rewind(input);//wczytywanie wielkosci pliku //reset strumiena dancyh
    x--;
    char **mapa;
    mapa = malloc((y+1)*sizeof(char*));
    for (int i = 0; i < (y+1); ++i) {
        mapa[i] =  malloc((x+1)*sizeof(char)); // to x+y to wyglada jak mocny blad ale XDDDD
    }
    int it = 0;
    while(fscanf(input,"%s",buff_t) != EOF){
        for (int i = 0; i < x; ++i) {
            mapa[it][i] = buff_t[i];
        }
        it++;
    }
    fclose(input);
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            //printf("%c",mapa[i][j]);
        }

        //printf("\n");
    }

    Node ***Graph;
    Graph = (Node***) malloc(y*sizeof(Node**));
    for (int i = 0; i < y; ++i) {
        Graph[i] = (Node**) malloc(x*sizeof(Node*));
    }
    if (Graph == NULL) {
        printf(stderr,"Allocation of new memory for Graph  failed");
        return 1;
    }

    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++) {
            Graph[i][j] = createNode(i, j);
            Graph[i][j]->letter = mapa[i][j];
            //printf("%d      %d  %d \n", Graph[0][0]->x , x, y);

        }
    } // [][] pierwsza kolumna jest pozioma, druga jest pionowa
    int BFSs[8096];
    int Ex;
    int Ey;
    int iter = 0;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            //printf("%c",Graph[i][j]->letter);
            if(Graph[i][j]->letter == 'E'){
                printf("End Node: y:%d x:%d\n",i,j);
                Ey = i;
                Ex = j;
            }
        }
        //printf("\n");
    }
    createNeighbours(Graph,x,y);
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            //printf("%c",Graph[i][j]->letter);
            if(Graph[i][j]->letter == 'a' || Graph[i][j]->letter == 'S'){
                BFSs[iter] = BFS(Graph,j,i,Ex,Ey);
                iter++;
                for (int i = 0; i < y; ++i) {
                    for (int j = 0; j < x; ++j) {
                        Graph[i][j]->visited=0;
                        }
                    }
            }
        }

    }
    int min = 1000;
    for (int i = 0; i < iter+1; ++i) {
        if (BFSs[i] < min && BFSs[i] > 0)
            min = BFSs[i];
    }
    printf("Anwser: %d",min);

    freeGraph(Graph,x,y);
    for (int i = 0; i < y+1; ++i) {
        free(mapa[i]);
    }
    free(mapa);
    return 0;
}
