//
// Created by wikapo on 5/21/25.
//

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct trie {
    int value;
    struct trie **next;
} trie_t;

typedef struct {
    int rootSize;
    int nextSize;
    trie_t *trie;
} config_t;

#endif //STRUCTS_H
