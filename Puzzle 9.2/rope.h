//
// Created by michal on 12.12.22.
//

#ifndef PROJECT_9_1V2_ROPE_H
#define PROJECT_9_1V2_ROPE_H

typedef struct Ropelink Ropelink;

struct Ropelink{
    Ropelink *previousLink;
    int x;
    int y;
};
Ropelink *createRopelink(Ropelink*,int,int );
Ropelink **createRope(int,int,int );
void freeRope(Ropelink**,int);
void printRope(Ropelink**,int);
#endif //PROJECT_9_1V2_ROPE_H
