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

void print(const config_t config) {
    trie_t *trie = config.trie;
    if (trie != NULL) {
        printf("%d ", trie->value);
        if (trie->next != NULL)
            for (int i = 0; i < config.rootSize; i++)
                doPrint(trie->next[i], config.nextSize);
    }
}

void insert(config_t *config, const int value) {
    if (config->trie == NULL) {
        init(&config->trie, value);
    } else {
        int size = config->rootSize;
        int check = value;
        trie_t **trie = &config->trie;

        while (*trie != NULL) {
            if ((*trie)->value == value) {
                printf("%d exist\n", value);
                return;
            }
            const int id = check % size;
            check /= size;
            if ((*trie)->next == NULL)
                (*trie)->next = calloc(size, sizeof(trie_t));

            trie = &(*trie)->next[id];
            size = config->nextSize;
        }

        init(trie, value);
    }
}

trie_t **find(config_t *config, const int value) {
    trie_t **trie = &config->trie;
    int size = config->rootSize;
    int check = value;
    while (*trie != NULL) {
        if ((*trie)->value == value) return trie;

        const int id = check % size;
        check /= size;
        if ((*trie)->next == NULL) break;

        trie = &(*trie)->next[id];
        size = config->nextSize;
    }
    return NULL;
}

void lookUp(config_t *config, const int value) {
    find(config, value) != NULL ? printf("%d exist\n", value) : printf("%d not exist\n", value);
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

void freeTrie(config_t *config) {
    trie_t **trie = &config->trie;
    if (*trie != NULL) {
        if ((*trie)->next != NULL) {
            for (int i = 0; i < config->rootSize; i++)
                doFreeTrie(&(*trie)->next[i], config->nextSize);
            free((*trie)->next);
        }
        free(*trie);
        *trie = NULL;
    }
}

void delete(config_t *config, const int value) {
    trie_t **trie = find(config, value);
    if (trie == NULL) {
        printf("%d not exist\n", value);
        return;
    }
    if ((*trie)->next == NULL) {
        free(*trie);
        *trie = NULL;
    } else {
        trie_t **leftmostExternalChild = trie;
        if (*leftmostExternalChild != NULL) {
            int size = *trie == config->trie ? config->rootSize : config->nextSize;
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
                size = config->nextSize;
            }
        }
        (*trie)->value = (*leftmostExternalChild)->value;
        free(*leftmostExternalChild);
        *leftmostExternalChild = NULL;
    }
}
