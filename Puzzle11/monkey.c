//
// Created by michal on 13.12.22.
//
#include "monkey.h"

#define BUFF_SIZE 64




uint64_t GCD(uint64_t x, uint64_t y){
    if(x == 0)
        return y;
    return GCD(y % x, x);
}
uint64_t LCM(uint64_t x, uint64_t y){return (x / GCD(x,y))*y;}

uint64_t BIG_LCM = 5*2*13*19*11*3*7*17;

uint64_t add(uint64_t x, uint64_t y) { return x + y;}


uint64_t multiply(uint64_t x, uint64_t y) { return x*y;}

uint64_t square(uint64_t x,uint64_t y) {return x*x; }


monkey *createMonkey(uint64_t num_t, uint64_t num_of_items_t, uint64_t *items_t, uint64_t operation_num_t,
                     uint64_t (*operation_t)(uint64_t, uint64_t), uint64_t test_by_div_t, uint64_t test_true_t,
                     uint64_t test_true_f) {
    monkey *crazyMonkey;
    crazyMonkey = (monkey* ) malloc(sizeof(monkey));
    crazyMonkey->num = num_t;
    crazyMonkey->items =items_t;
    crazyMonkey->num_of_items = num_of_items_t;
    crazyMonkey->operation_num = operation_num_t;
    crazyMonkey->operation =  operation_t;
    crazyMonkey->test_by_div = test_by_div_t;
    crazyMonkey->test_true = test_true_t;
    crazyMonkey->test_false = test_true_f;
    return crazyMonkey;
}

monkey *monkeysRead(FILE* input){ //this is like very stuuuupid reading files but i hope it will work //it works very nice :))))
    char buff[BUFF_SIZE];
    uint64_t num_tt;
    uint64_t (*operation)(uint64_t,uint64_t);
    uint64_t temp[BUFF_SIZE];
    fscanf(input,"%s",buff); //Monkey - we can ignore it
    fscanf(input,"%s",buff); //0:\n,1:\n...
    num_tt = atol(buff);
    printf("Monkey %d is reading. \n",num_tt);
    fscanf(input,"%s",buff); //\tStarting
    fscanf(input,"%s",buff); //items:
    uint64_t i = 0;
    do{ //beacuse all items are write like XX, XX, XX, XX, XX, XX this code may be faulty for other types of input
        fscanf(input,"%s",buff);
        temp[i] = atol(buff);
        i++;
    }while(buff[2] != '\0');
    uint64_t num_of_items_t = i;
    uint64_t *items_t;
    items_t = (uint64_t* )calloc(i,sizeof(uint64_t));
    for (int j = 0; j < i; ++j) {
        items_t[j] = temp[j];
    }
    fscanf(input,"%s",buff); //\tOperation
    fscanf(input,"%s",buff); //new
    fscanf(input,"%s",buff); //=
    fscanf(input,"%s",buff); //old
    fscanf(input,"%s",buff); //its either "+" or "*"
    if(buff[0] == '+'){
        operation = &add;
    }
    else if(buff[0] == '*'){
        operation = &multiply;
    }
    else{
        printf("Scanning failed");
    }
    fscanf(input,"%s",buff); //its a number like 3 10 23 so just easy
    if(buff[0] == 'o'){
        operation = &square;
    }

    uint64_t operation_num_t = atol(buff);
    fscanf(input,"%s",buff); // /tTest:
    fscanf(input,"%s",buff); //divisible
    fscanf(input,"%s",buff); //by
    fscanf(input,"%s",buff); //num
    uint64_t test_div_t = atol(buff);
    fscanf(input,"%s",buff); // /tIf:
    fscanf(input,"%s",buff); //True
    fscanf(input,"%s",buff); //throw
    fscanf(input,"%s",buff); //to
    fscanf(input,"%s",buff); //monkey
    fscanf(input,"%s",buff); //num
    uint64_t test_t_t = atol(buff);
    fscanf(input,"%s",buff); // /tIf:
    fscanf(input,"%s",buff); //False
    fscanf(input,"%s",buff); //throw
    fscanf(input,"%s",buff); //to
    fscanf(input,"%s",buff); //monkey
    fscanf(input,"%s",buff); //num
    uint64_t test_f_t = atol(buff);

    return createMonkey(num_tt,num_of_items_t,items_t,operation_num_t,operation,test_div_t,test_t_t,test_f_t);
}

uint64_t monkeyBusines(monkey** monkeyTroop, uint64_t num_of_monkeys,uint64_t num_of_rounds) {
    uint64_t sums[num_of_monkeys];
    for (uint64_t i = 0; i < num_of_monkeys; ++i) {
        sums[i] = 0;
    }
    for (uint64_t i = 0; i < num_of_rounds; ++i) {
        for (uint64_t j = 0; j < num_of_monkeys; ++j) {
            if (monkeyTroop[j]->num_of_items == 0) {
                //printf("Monkey %d has no items \n", j);
            } else {
                for (uint64_t k = 0; k < monkeyTroop[j]->num_of_items; ++k) {
                    monkeyTroop[j]->items[k] = (
                            monkeyTroop[j]->operation(monkeyTroop[j]->items[k], monkeyTroop[j]->operation_num))%BIG_LCM; //tu dzieli przez 3 lub uzywa Least Common Multiplier
                    if ((monkeyTroop[j]->items[k]) % (monkeyTroop[j]->test_by_div) == 0) {                                //uzylem tu wskazowek z reddita ale rozumiem rozwiazanie a sam by na to nie wpadl xD
                        throwToMonkey(monkeyTroop, monkeyTroop[j]->test_true, j, k);
                        //printf("%d: %d  %d div %d true %d false %dT\n", j, monkeyTroop[j]->items[k],
                              // monkeyTroop[j]->operation_num, monkeyTroop[j]->test_by_div, monkeyTroop[j]->test_true,
                               //monkeyTroop[j]->test_false);
                        //printf("%d\n",monkeyTroop[j]->test_by_div);
                    } else {
                        throwToMonkey(monkeyTroop, monkeyTroop[j]->test_false, j, k);
                        //printf("%d: %d  %d div %d true %d false %dN\n", j, monkeyTroop[j]->items[k],
                               //monkeyTroop[j]->operation_num, monkeyTroop[j]->test_by_div, monkeyTroop[j]->test_true,
                              // monkeyTroop[j]->test_false);
                            //printf("%d\n",monkeyTroop[j]->test_by_div);
                    }
                }
                free(monkeyTroop[j]->items);
                monkeyTroop[j]->items = NULL;
                sums[j] = sums[j] + monkeyTroop[j]->num_of_items;
                monkeyTroop[j]->num_of_items = 0;
            }

            }


    for (int w = 0; w < num_of_monkeys; ++w) {
        //printf("%d: %d   ", w, monkeyTroop[w]->num_of_items);
        for (int j = 0; j < monkeyTroop[w]->num_of_items; ++j) {
            //printf(" %d\n",monkeyTroop[w]->items[j]);
        }
    }
    }
        uint64_t monkeyAnwser = 1;
        uint64_t max = 0;
        int loc_max = 0;
        for (int i = 0; i < num_of_monkeys; ++i) {
           // printf("%d: %d\n", i, sums[i]);
            if (sums[i] > max) {

                max = sums[i];
                loc_max = i;
            }
        }
        sums[loc_max] = 0;
        monkeyAnwser *= max;
        max = 0;
        for (int i = 0; i < num_of_monkeys; ++i) {
            if (sums[i] > max) {
                max = sums[i];
                loc_max = i;
            }
        }
        monkeyAnwser *= max;

        return monkeyAnwser;
    }

    void throwToMonkey(monkey **pMonkey, uint64_t MonkeyGet, uint64_t MonkeyThrow, uint64_t itemThrown) {
        pMonkey[MonkeyGet]->num_of_items +=1;
        //printf("Monkey %d throws to monkey %d item %d.Monkey thats gets those items will have: %d\n",MonkeyThrow,MonkeyGet,pMonkey[MonkeyThrow]->items[itemThrown],pMonkey[MonkeyGet]->num_of_items);
        uint64_t *temp;
        if (pMonkey[MonkeyGet]->items == NULL) {
            pMonkey[MonkeyGet]->items = (uint64_t *) malloc(sizeof(uint64_t));
        } else {
            pMonkey[MonkeyGet]->items = realloc(pMonkey[MonkeyGet]->items, sizeof(uint64_t) * (pMonkey[MonkeyGet]->num_of_items));
        }
        pMonkey[MonkeyGet]->items[pMonkey[MonkeyGet]->num_of_items-1] = pMonkey[MonkeyThrow]->items[itemThrown]; //Tutaj rzuca przedmiot
    }


    void releaseTheMonkeys(monkey** monkeys,uint8_t num_of_monkeys){
        for (int i = 0; i < num_of_monkeys; ++i) {
            free(monkeys[i]);
        }
        free(monkeys);
}
