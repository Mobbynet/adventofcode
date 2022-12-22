#include "monkey.h"

#define FILE_READ "/home/michal/Studia/AdventOfCode/Puzzle11/input"
#define NUM_OF_MONKEYS 8
#define NUM_OF_ROUNDS 10000


int main() {
    FILE *input;
    input = fopen(FILE_READ,"r");
    monkey **monkeyTroop;
    char buff[64];
    monkeyTroop = (monkey** )malloc(NUM_OF_MONKEYS*sizeof(monkey*));
    for(int i =0;i < NUM_OF_MONKEYS;i++){
        monkeyTroop[i] = monkeysRead(input);
    }
    printf("Monkeys are now literate.\n*Initialize monkey business* \n");
    printf("Monkey business concluded at a level of %ld \n",monkeyBusines(monkeyTroop,NUM_OF_MONKEYS,NUM_OF_ROUNDS));
    releaseTheMonkeys(monkeyTroop, NUM_OF_MONKEYS);
    return 0;
}
