#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "trie.h"

int main(void) {
    int n, min, max;
    config_t config;

    scanf("%d", &n);
    scanf("%d %d", &min, &max);
    scanf("%d %d", &config.rootSize, &config.nextSize);

    config.trie = NULL;

    char command;
    int value;
    for (int i = 0; i < n; i++) {
        do
            scanf("%c", &command);
        while (!(command == 'P' || command == 'I' || command == 'L' || command == 'D'));
        if (command == 'P') {
            print(config);
            printf("\n");
            continue;
        }
        scanf("%d", &value);
        switch (command) {
            case 'I':
                insert(&config, value);
                break;
            case 'L':
                lookUp(&config, value);
                break;
            case 'D':
                delete(&config, value);
                break;
            default:
                break;
        }
    }

    freeTrie(&config);
    return 0;
}
