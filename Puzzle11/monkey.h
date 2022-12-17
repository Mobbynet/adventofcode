//
// Created by michal on 13.12.22.
//

#ifndef PUZZLE11_MONKEY_H
#define PUZZLE11_MONKEY_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





typedef struct monkey monkey;

struct monkey{
    uint64_t num;
    uint64_t num_of_items;
    uint64_t *items;
    uint64_t operation_num;
    uint64_t (*operation)(uint64_t,uint64_t);
    uint64_t test_by_div;
    uint64_t test_true;
    uint64_t test_false;
};

uint64_t add(uint64_t x,uint64_t y);
uint64_t multiply(uint64_t x, uint64_t y);
uint64_t square(uint64_t x,uint64_t y);
monkey * createMonkey(uint64_t num_t,uint64_t num_of_items_t,uint64_t *items_t, uint64_t operation_num_t, uint64_t (*operation_t)(uint64_t, uint64_t),
             uint64_t test_by_div_t, uint64_t test_true_t, uint64_t test_true_f); //mocne spaghetii, zajelo mi to jakies z 3 godziny bo kilka roznych val bylo blednych ktore tam dawalem
monkey *monkeysRead(FILE*);

uint64_t monkeyBusines(monkey** ,uint64_t,uint64_t);
void throwToMonkey(monkey**,uint64_t,uint64_t,uint64_t);
void releaseTheMonkeys(monkey**,uint8_t);

uint64_t GCD(uint64_t x, uint64_t y);

uint64_t LCM(uint64_t x, uint64_t y);

#endif //PUZZLE11_MONKEY_H
