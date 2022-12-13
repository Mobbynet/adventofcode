//
// Created by michal on 13.12.22.
//

#ifndef PUZZLE10_1_REGISTER_H
#define PUZZLE10_1_REGISTER_H

#include <stdint.h>


#define REGISTER_SIZE 255

typedef struct Register Register;
struct Register{
    uint8_t cycle;
    uint16_t reg[REGISTER_SIZE];
};



#endif //PUZZLE10_1_REGISTER_H
