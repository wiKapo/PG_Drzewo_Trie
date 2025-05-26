//
// Created by wikapo on 5/21/25.
//

#include "trie.h"

void init(trie_t **trie, const int value) {
    *trie = malloc(sizeof(trie_t));
    (*trie)->value = value;
    (*trie)->next = NULL;
}

void doPrint(const trie_t *trie, const int size) {
    if (trie != NULL) {
        printf("%d ", trie->value);
        if (trie->next != NULL)
            for (int i = 0; i < size; i++)
                doPrint(trie->next[i], size);
    }
}

void print(const trie_t *trie, const int rootSize, const int nextSize) {
    if (trie != NULL) {
        printf("%d ", trie->value);
        if (trie->next != NULL)
            for (int i = 0; i < rootSize; i++)
                doPrint(trie->next[i], nextSize);
    }
}

void insert(trie_t **trie, const int value, const int rootSize, const int nextSize) {
    int size = rootSize;
    int check = value;

    while (*trie != NULL) {
        if ((*trie)->value == value) {
            printf("%d exist\n", value);
            return;
        }
        const int id = check % size;
        check /= size;
        if ((*trie)->next == NULL)
            (*trie)->next = calloc(size - 2, sizeof(trie_t));

        trie = &(*trie)->next[id];
        size = nextSize;
    }

    init(trie, value);
}

trie_t **find(trie_t **trie, const int value, const int rootSize, const int nextSize) {
    int size = rootSize;
    int check = value;
    while (*trie != NULL) {
        if ((*trie)->value == value) return trie;

        const int id = check % size;
        check /= size;
        if ((*trie)->next == NULL) break;

        trie = &(*trie)->next[id];
        size = nextSize;
    }
    return NULL;
}

void lookUp(trie_t **trie, const int value, const int rootSize, const int nextSize) {
    find(trie, value, rootSize, nextSize) != NULL ? printf("%d exist\n", value) : printf("%d not exist\n", value);
}

void doFreeTrie(trie_t **trie, const int size) {
    if (*trie != NULL) {
        if ((*trie)->next != NULL) {
            for (int i = 0; i < size; i++)
                doFreeTrie(&(*trie)->next[i], size);
            free((*trie)->next);
        }
        free(*trie);
        *trie = NULL;
    }
}

void freeTrie(trie_t **trie, const int rootSize, const int nextSize) {
    if (*trie != NULL) {
        if ((*trie)->next != NULL) {
            for (int i = 0; i < rootSize; i++)
                doFreeTrie(&(*trie)->next[i], nextSize);
            free((*trie)->next);
        }
        free(*trie);
        *trie = NULL;
    }
}

void delete(trie_t **trie, const int value, const int rootSize, const int nextSize) {
    trie_t **foundTrie = find(trie, value, rootSize, nextSize);
    if (foundTrie == NULL) {
        printf("%d not exist\n", value);
        return;
    }
    if ((*foundTrie)->next == NULL) {
        free(*foundTrie);
        *foundTrie = NULL;
    } else {
        trie_t **leftmostExternalChild = foundTrie;
        if (*leftmostExternalChild != NULL) {
            int size = foundTrie == trie ? rootSize : nextSize;
            while ((*leftmostExternalChild)->next != NULL) {
                bool found = false;
                for (int i = 0; i < size; i++) {
                    if ((*leftmostExternalChild)->next[i] != NULL) {
                        leftmostExternalChild = &(*leftmostExternalChild)->next[i];
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    free((*leftmostExternalChild)->next);
                    (*leftmostExternalChild)->next = NULL;
                    break;
                }
                size = nextSize;
            }
        }
        (*foundTrie)->value = (*leftmostExternalChild)->value;
        free(*leftmostExternalChild);
        *leftmostExternalChild = NULL;
    }
}
