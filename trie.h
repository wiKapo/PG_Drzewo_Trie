//
// Created by wikapo on 5/21/25.
//

#ifndef TRIE_H
#define TRIE_H

#include "structs.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print(config_t config);

void insert(config_t *config, const int value);

void lookUp(config_t *config, const int value);

void delete(config_t *config, const int value);

void freeTrie(config_t *config);

#endif //TRIE_H
/*
29
0 511
8 4

I 3
I 31
I 150
I 190
I 130
I 174
I 81
I 30
I 203
P
L 32
L 30
L 150
Q

 */