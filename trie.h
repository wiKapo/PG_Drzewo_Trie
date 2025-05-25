//
// Created by wikapo on 5/21/25.
//

#ifndef TRIE_H
#define TRIE_H

typedef struct trie {
    int value;
    struct trie **next;
} trie_t;

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print(const trie_t *trie, const int rootSize, const int nextSize);

void insert(trie_t **trie, const int value, const int rootSize, const int nextSize);

void lookUp(trie_t **trie, const int value, const int rootSize, const int nextSize);

void delete(trie_t **trie, const int value, const int rootSize, const int nextSize);

void freeTrie(trie_t **trie, const int rootSize, const int nextSize);

#endif //TRIE_H