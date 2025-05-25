#include <stdio.h>

#include "trie.h"

int main(void) {
    int n, min, max;
    int rootSize, nextSize;

    scanf("%d", &n);
    scanf("%d %d", &min, &max);
    scanf("%d %d", &rootSize, &nextSize);

    trie_t *trie = NULL;

    char command;
    int value;
    for (int i = 0; i < n; i++) {
        do
            scanf("%c", &command);
        while (!(command == 'P' || command == 'I' || command == 'L' || command == 'D'));
        if (command == 'P') {
            print(trie, rootSize, nextSize);
            printf("\n");
            continue;
        }
        scanf("%d", &value);
        switch (command) {
            case 'I':
                insert(&trie, value, rootSize, nextSize);
                break;
            case 'L':
                lookUp(&trie, value, rootSize, nextSize);
                break;
            case 'D':
                delete(&trie, value, rootSize, nextSize);
                break;
            default:
                break;
        }
    }

    freeTrie(&trie, rootSize, nextSize);
    return 0;
}
