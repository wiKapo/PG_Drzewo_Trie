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

        switch (command) {
            case 'P':
                print(trie, rootSize, nextSize);
                printf("\n");
                break;
            case 'I':
                scanf("%d", &value);
                if (!insert(&trie, value, rootSize, nextSize))
                    printf("%d exist\n", value);
                break;
            case 'L':
                scanf("%d", &value);
                if (lookUp(&trie, value, rootSize, nextSize))
                    printf("%d exist\n", value);
                else
                    printf("%d not exist\n", value);
                break;
            case 'D':
                scanf("%d", &value);
                if (!delete(&trie, value, rootSize, nextSize))
                    printf("%d not exist\n", value);
                break;
            default:
                break;
        }
    }

    freeTrie(&trie, rootSize, nextSize);
    return 0;
}
